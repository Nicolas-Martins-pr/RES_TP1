//
// Created by nicol on 01/10/2021.
//

#include "TCPConnection.h"

#include <iostream>

using namespace std;

TCPConnection::TCPConnection(SOCKET listenSocket, SOCKET connectSocket) : Connection(listenSocket, connectSocket)
{


	
	Send("Je suis un client et je repond.");
	//Receive terminal?
	//Callbacks ?
	

}

void TCPConnection::Receive()
{
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	int iResult;

	// Receive until the peer closes the connection
	iResult = recv(getConnectSocket(), recvbuf, recvbuflen, 0);
	if (iResult > 0)
	{
		printf("Bytes received : %d, message received : %s\n", iResult, recvbuf);
	}
	else if (iResult == 0)
		printf("Connection closed\n");
	else
		printf("recv failed with error: %d\n", WSAGetLastError());

	
}

void TCPConnection::Send(char* message)
{
	// Send an initial buffer
	int iResult = send(getConnectSocket(), message, (int)strlen(message) + 1, 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(getConnectSocket());
		WSACleanup();
		//return 1;
	}

	printf("Bytes sent: %ld, message sent : %s\n", iResult, message);
}


