//
// Created by nicol on 01/10/2021.
//

#include "terminal.h"

#include <iostream>

#include "TCPConnection.h"

terminal::terminal(SOCKET listenSocket)
{

	while (true)
	{
		// Accept a client socket
		clientSocket = accept(listenSocket, NULL, NULL);
		if (clientSocket == INVALID_SOCKET) {
			printf("accept failed with error: %d\n", WSAGetLastError());
			closesocket(listenSocket);
			WSACleanup();
		}
		else
		{
			//Create a connection for the client socket
			TCPConnection connection = TCPConnection(listenSocket, clientSocket);


			std::string messageToSend;
			std::cout << "Entrez un message à envoyer au client : \n";
			std::cin.get();
			getline(std::cin, messageToSend);
			char* messageAsChars = messageToSend.data();
			connection.Send(messageAsChars);

			//connection.Send("Bien le bonjour dans mon serveur paysans");
			connection.Receive();
		}

	}
}

