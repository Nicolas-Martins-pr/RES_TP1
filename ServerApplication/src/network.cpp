//
// Created by nicol on 01/10/2021.
//

#include "network.h"

network::network(char* ipAdress, char* port)
{

	WSADATA wsaData;
	int iResult;
	//int iSendResult;

	SOCKET clientSocket = INVALID_SOCKET;

	struct addrinfo* resultTCP = NULL;
	struct addrinfo* resultUDP = NULL;

	struct addrinfo hintsUDP, hintsTCP;

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

	ZeroMemory(&hintsUDP, sizeof(hintsUDP));
	hintsUDP.ai_family = AF_INET;
	hintsUDP.ai_socktype = SOCK_DGRAM;
	hintsUDP.ai_protocol = IPPROTO_UDP;
	hintsUDP.ai_flags = AI_PASSIVE;

	ZeroMemory(&hintsTCP, sizeof(hintsTCP));
	hintsTCP.ai_family = AF_INET;
	hintsTCP.ai_socktype = SOCK_STREAM;
	hintsTCP.ai_protocol = IPPROTO_TCP;
	hintsTCP.ai_flags = AI_PASSIVE;

	// Resolve the server address and port for TCP
	iResult = getaddrinfo(NULL, port, &hintsTCP, &resultTCP);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		//return 1;
	}

	// Resolve the server address and port for UDP
	iResult = getaddrinfo(NULL, port, &hintsUDP, &resultUDP);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		//return 1;
	}


	//Create a TCP SOCKET for connecting to server
	listenSocketTCP = socket(resultTCP->ai_family, resultTCP->ai_socktype, resultTCP->ai_protocol);
	if (listenSocketTCP == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(resultTCP);
		WSACleanup();
		//return 1;
	}

	//Create a UDP SOCKET for connecting to server
	listenSocketUDP = socket(resultUDP->ai_family, resultUDP->ai_socktype, resultUDP->ai_protocol);
	if (listenSocketUDP == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(resultUDP);
		WSACleanup();
		//return 1;
	}

	printf("Sockets created.\n");

	//On traduit nos données réseaux
	/*sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(DEFAULT_PORT);
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);*/

	//Setup the listening socket for TCP
	iResult = bind(listenSocketTCP, resultTCP->ai_addr, (int)resultTCP->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(resultTCP);
		closesocket(listenSocketTCP);
		WSACleanup();
		//return 1;
	}

	//Setup the listening socket for UDP
	iResult = bind(listenSocketUDP, resultUDP->ai_addr, (int)resultUDP->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(resultUDP);
		closesocket(listenSocketUDP);
		WSACleanup();
		//return 1;
	}

	freeaddrinfo(resultTCP);
	freeaddrinfo(resultUDP);

	puts("Binded\n");





	//Listen to incoming connections
	iResult = listen(listenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(listenSocket);
		WSACleanup();
		//return 1;
	}

	// Accept a client socket TERMINAL
	clientSocket = accept(listenSocket, NULL, NULL);
	if (clientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(listenSocket);
		WSACleanup();
		//return 1;
	}

	// No longer need server socket
	closesocket(listenSocket);



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
}

void network::Listen()
{

}

void network::Connect()
{

}

void network::Update()
{

}

