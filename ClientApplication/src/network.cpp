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
	}

	
	Connect(result, port, (char *) ipAdressAsPCSTR);


	/*


	// Receive until the peer shuts down the connection
	do {

		iResult = recv(clientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);
			printf(recvbuf);
			// Echo the buffer back to the sender
			iSendResult = send(clientSocket, recvbuf, iResult, 0);
			if (iSendResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(clientSocket);
				WSACleanup();
				//return 1;
			}
			printf("\n Bytes sent: %d\n", iSendResult);
		}
		else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv failed with error: %d\n", WSAGetLastError());
			closesocket(clientSocket);
			WSACleanup();
			//return 1;
		}

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(clientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(clientSocket);
		WSACleanup();
		//return 1;
	}



	// cleanup
	closesocket(clientSocket);
	WSACleanup();

	*/
}

void network::InitListen(addrinfo* result)
{
}





//Créée Connection pour le client + créée socket de connection au serveur
void network::Connect(addrinfo* result, int port, char * adresse)
{

	// Create a SOCKET for connecting to server
	SOCKET connectSocket = socket(result->ai_family, result->ai_socktype,
		result->ai_protocol);
	if (connectSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
	} else
	{
		printf("Socket created.\n");
	}
		

	if (result->ai_protocol == IPPROTO_UDP)
	{
		
		UDPConnection connection = UDPConnection(connectSocket, *result->ai_addr);
		//std::thread listenThread(&network::ListenServer, this, connection);


		std::thread listenInputThread(&terminal::ListenInputUDP, terminal(), connection, port, adresse);

		/*if (listenThread.joinable())
			listenThread.join();*/
		if (listenInputThread.joinable())
			listenInputThread.join();
		
	}
	else if (result->ai_protocol == IPPROTO_TCP)
	{

		// Connect to server.
		int iResult = connect(connectSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(connectSocket);
			printf("Unable to connect to server!\n");
			WSACleanup();
		} else
		{
			puts("Connected to server.\n");
		}

		TCPConnection connection = TCPConnection(listenSocket, connectSocket);
		std::thread listenThread(&network::ListenServer, this, connection);
		std::thread listenInputThread(&terminal::ListenInputTCP, terminal(), connection);

		if (listenThread.joinable())
			listenThread.join();
		if (listenInputThread.joinable())
			listenInputThread.join();

	}
		



	freeaddrinfo(result);
}


void network::ListenUpdate(SOCKET socketToListen)
{
}



void network::ListenServer(TCPConnection connection)
{

	while (true)
	{
		char* message = connection.Receive();
		//leave if fail TODO
	}

}

