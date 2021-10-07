//
// Created by nicol on 01/10/2021.
//

#include "terminal.h"

#include <iostream>

#include "TCPConnection.h"
#include "UDPConnection.h"

terminal::terminal(SOCKET listenSocket) 
{


}
/*void terminal::WriteMessage(TCPConnection connection)
{
	std::string messageToSend;
	std::cout << "Entrez un message à envoyer au client : \n";
	std::cin.get();
	getline(std::cin, messageToSend);
	char* messageAsChars = messageToSend.data();

	connection.Send(messageAsChars);
	
}
*/
