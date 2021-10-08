#include "TCPConnection.h"
#include <iostream>
#include <string>

using namespace std;

TCPConnection::TCPConnection(SOCKET listenSocket, SOCKET connectSocket) : Connection(listenSocket, connectSocket)
{

}

char * TCPConnection::Receive()
{
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
    int iResult;

	// Receive
	iResult = recv(getConnectSocket(), recvbuf, recvbuflen, 0);
	if (iResult > 0)
	{
		printf("Bytes received : %d, message received : %s, from server\n", iResult, recvbuf);

	}
	else if (iResult == 0)
		printf("Connection closed\n");
	else {
		printf("recv failed with error: %d\n", WSAGetLastError());
		closesocket(getConnectSocket());
		WSACleanup();
		std::getchar();
	}
	return recvbuf;
}

void TCPConnection::Send(char* message)
{
	// Send an initial buffer
	int iResult = send(getConnectSocket(), message, (int)strlen(message) + 1, 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(getConnectSocket());
		WSACleanup();
    }
	printf("Bytes sent: %ld, message sent to server and other clients : %s\n", iResult, message);
}
