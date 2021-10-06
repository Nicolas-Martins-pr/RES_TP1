//
// Created by nicol on 01/10/2021.
//

#include "terminal.h"

#include "TCPConnection.h"

terminal::terminal(SOCKET listenSocket)
{

	// Accept a client socket
	clientSocket = accept(listenSocket, NULL, NULL);
	if (clientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(listenSocket);
		WSACleanup();
	}

	//Create a connection for the client socket
	TCPConnection connection = TCPConnection(listenSocket, clientSocket);

}

