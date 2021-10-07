//
// Created by nicol on 01/10/2021.
//

#include "TCPConnection.h"

#include <string>


TCPConnection::TCPConnection(SOCKET listenSocket, SOCKET connectSocket) : Connection(listenSocket, connectSocket)
{
	
}

char * TCPConnection::Receive()
{
	char * recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	int iResult;

	// Receive
	iResult = recv(getConnectSocket(), reinterpret_cast<char*>(recvbuf), recvbuflen, 0);
	if (iResult > 0)
	{
		printf("\n\n\nBytes received : %d, message received : %s, from client %s\n", iResult, recvbuf, std::to_string(getConnectSocket()).c_str());

	}
	else if (iResult == 0)
		printf("Connection closed\n");
	else
	{
		
		printf("recv failed with error: %d\n", WSAGetLastError());
		closesocket(getConnectSocket());
		WSACleanup();
		throw "Connection closed, recv failed !\n";
	}


	return reinterpret_cast<char*>(recvbuf);


}

void TCPConnection::Send(char * message) // ,TCPConnection senderSocket)
{


	// Send an initial buffer
	int iResult = send(getConnectSocket(), message, (int)strlen(message) + 1, 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(getConnectSocket());
		WSACleanup();
		//return 1;
	}

	printf("Bytes sent: %ld, message sent to other clients : %s\n", iResult, message);
}


