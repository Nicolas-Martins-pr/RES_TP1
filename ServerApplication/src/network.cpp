//
// Created by nicol on 01/10/2021.
//

#include "network.h"
#include <iostream>
#include <thread>

#include "TCPConnection.h"
#include "UDPConnection.h"

network::network(int protocol, std::string ipAdress, int port)
{

	WSADATA wsaData;
	int iResult;
	//int iSendResult;

	struct addrinfo* result = NULL;

	struct addrinfo hints;

	//char recvbuf[DEFAULT_BUFLEN];
	//int recvbuflen = DEFAULT_BUFLEN;

	//Initialise Winsock
	printf("\nInitialising Winsock...");

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed: %d\n", iResult);
		//return 1;
	}

	printf("Initialised.\n");


	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_flags = AI_PASSIVE;

	if (protocol == 0) {
		hints.ai_socktype = SOCK_DGRAM;
		hints.ai_protocol = IPPROTO_UDP;
	}
	else if (protocol == 1) {
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
	}

	const char* ipAdressAsPCSTR = ipAdress.c_str();

	std::string portAsString = std::to_string(port);
	char const* portAsPCSTR = portAsString.c_str();

	// Resolve the server address and port
	iResult = getaddrinfo(ipAdressAsPCSTR, portAsPCSTR, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		//return 1;
	}


	InitListen(result);

}

void network::InitListen(addrinfo* result)
{

	//Create a SOCKET for connecting to server
	listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (listenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
	}



	printf("Socket created.\n");

	//Setup the listening socket
	int iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(listenSocket);
		WSACleanup();
	}


	puts("Binded\n");

	if (result->ai_protocol == IPPROTO_TCP)
	{
		freeaddrinfo(result);
		//intListen to incoming connections
		iResult = listen(listenSocket, SOMAXCONN);
		if (iResult == SOCKET_ERROR) {
			printf("listen failed with error: %d\n", WSAGetLastError());
			closesocket(listenSocket);
			WSACleanup();
		}


	}


	//TODO
	//freeaddrinfo(result);


	std::thread listenThread(&network::ListenUpdate, this, listenSocket);
	if (listenThread.joinable())
		listenThread.join();

	closesocket(listenSocket);

		
}


//Cr��e Connection pour le client + cr��e socket de connection au serveur
void network::Connect(addrinfo* result)
{

	// Create a SOCKET for connecting to server
	SOCKET connectSocket = socket(result->ai_family, result->ai_socktype,
		result->ai_protocol);
	if (connectSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		//return 1;
	}

	// Connect to server.
	int iResult = connect(connectSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(connectSocket);
		connectSocket = INVALID_SOCKET;
	}

	if (connectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		//return 1;
	}

	puts("Connected to server.\n");

	if (result->ai_protocol == IPPROTO_UDP)
		UDPConnection connection = UDPConnection(listenSocket, connectSocket);
	else if (result->ai_protocol == IPPROTO_TCP)
		TCPConnection connection = TCPConnection(listenSocket, connectSocket);



	freeaddrinfo(result);
}

void network::ListenUpdate(SOCKET socketToListen)
{
	FD_ZERO(&socketList);

	while(true)
	{

		// Accept a client socket
		SOCKET clientSocketTCP = accept(socketToListen, NULL, NULL);
		if (clientSocketTCP == INVALID_SOCKET) {
			printf("accept failed with error: %d\n", WSAGetLastError());
			closesocket(socketToListen);
			WSACleanup();
		}
		else
		{
			FD_SET(clientSocketTCP, &socketList);
			//Create a connection for the client socket
			std::cout << "Create a new client connection with socket " << std::to_string(clientSocketTCP).c_str() << "\n";
			TCPConnection connection = TCPConnection(socketToListen, clientSocketTCP);
			std::thread listenThread(&network::ListenClient, this, connection);
			listenThread.detach();
		}

	}

}


void network::ListenClient(TCPConnection clientConnection)
{
	
	while (true)
	{
		char* message = "";

		try {
			message = clientConnection.Receive();
		} catch (const char * msg)
		{
			printf(msg);
			break;
		}

		for (int i = 0 ; i < socketList.fd_count; i++)
		{
			if(strcmp(std::to_string(socketList.fd_array[i]).c_str(),std::to_string(clientConnection.getConnectSocket()).c_str()) != 0)
			{

				int iResult = send(socketList.fd_array[i], message, (int)strlen(message) + 1, 0);
				if (iResult == SOCKET_ERROR) {
					printf("send failed with error: %d\n", WSAGetLastError());
					closesocket(socketList.fd_array[i]);
					WSACleanup();
				}

				printf("Bytes sent: %ld, message sent to client %s : %s\n", iResult, std::to_string(socketList.fd_array[i]).c_str() ,message);


			}
		}
	}

}


