//
// Created by nicol on 01/10/2021.
//

#include "terminal.h"

terminal::terminal(SOCKET listenSocket) 
{

	// Accept a client socket
	clientSocketTCP = accept(listenSocket, NULL, NULL);
	if (clientSocketTCP == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(listenSocket);
		WSACleanup();
	}

}

