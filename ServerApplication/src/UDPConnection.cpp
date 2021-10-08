#include "UDPConnection.h"

#include <iostream>
#include <string>


UDPConnection::UDPConnection(SOCKET listenSocket) : Connection(listenSocket, NULL)
{

}

void UDPConnection::Receive()
{

	sockaddr_in clientAddr;
	int clientAddrLength = sizeof(clientAddr);
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	int iResult;
	iResult = recvfrom(getServerSocket(), recvbuf, recvbuflen, 0,(SOCKADDR *) &clientAddr, &clientAddrLength);

	if(iResult == SOCKET_ERROR)
	{
		printf("recvfrom failed with error %d\n", WSAGetLastError());
	} else
	{
		printf("Message received : %s\n", recvbuf);
	}

}

void UDPConnection::Send(char* message)
{
	sockaddr clientAddr;
	int clientAddrLength = sizeof(clientAddr);
	int iResult;

	iResult = sendto(getServerSocket(), message, sizeof(message), 0, &clientAddr, clientAddrLength);

	if (iResult == SOCKET_ERROR)
	{
		printf("sendto failed with error: %d\n", WSAGetLastError());
		closesocket(getServerSocket());
		WSACleanup();
	}
	else
	{
		printf("Message sent : %s\n", message);
	}
}
