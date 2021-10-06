//
// Created by nicol on 01/10/2021.
//

#include "UDPConnection.h"


UDPConnection::UDPConnection(SOCKET listenSocket, SOCKET connectSocket) : Connection(listenSocket, connectSocket)
{

}

void UDPConnection::Receive()
{
	sockaddr clientAddr;
	socklen_t clientAddrLength;
	char* buffer = (char*)malloc(1024 * sizeof(char));

	recvfrom(getServerSocket(), buffer, 1024, 0, &clientAddr, &clientAddrLength);

	printf("Message received : %s\n", buffer);
}

void UDPConnection::Send(char* message)
{
	sockaddr clientAddr;
	socklen_t clientAddrLength;

	sendto(getServerSocket(), message, 1024, 0, &clientAddr, clientAddrLength);

	printf("Message sent : %s\n", message);
}
