//
// Created by nicol on 01/10/2021.
//

#include "UDPConnection.h"

#include <iostream>
#include <string>


UDPConnection::UDPConnection(SOCKET listenSocket, sockaddr ipAddr) : Connection(listenSocket, NULL), targetIP(ipAddr)
{

}

void UDPConnection::Receive()
{
	sockaddr clientAddr;
	int clientAddrLength = sizeof(clientAddr);
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	int iResult;

	iResult = recvfrom(getServerSocket(), recvbuf, recvbuflen, 0, &clientAddr, &clientAddrLength);

	if (iResult == SOCKET_ERROR)
	{
		printf("recvfrom failed with error %d\n", WSAGetLastError());
	}
	else
	{
		printf("Message received : %s\n", recvbuf);
	}

}

void UDPConnection::Send(char* message, int port, char * adresse)
{
	int iResult;
	sockaddr_in RecvAddr;
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = port;
	RecvAddr.sin_addr.s_addr = inet_addr(adresse);

	std::cout << port << "   " << adresse << "\n";
	iResult = sendto(getServerSocket(), message, sizeof(message), 0, reinterpret_cast<SOCKADDR*>(&RecvAddr), sizeof(RecvAddr));

	if (iResult == SOCKET_ERROR)
	{
		printf("sendto failed with error: %d\n", WSAGetLastError());
		closesocket(getServerSocket());
		WSACleanup();
	} else
	{
		printf("Message sent : %s\n", message);
	}

}
