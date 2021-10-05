//
// Created by nicol on 01/10/2021.
//

#include "terminal.h"

terminal::terminal() {

	// Accept a client socket
	clientSocket = accept(listenSocket, NULL, NULL);
	if (clientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	closesocket(listenSocket);


}

/*int main :: network(){

}*/