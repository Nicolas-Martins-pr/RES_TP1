#include "terminal.h"

#include <iostream>

#include "TCPConnection.h"

terminal::terminal()
{

}

// TODO tres tres moche !
void terminal::ListenInputTCP(TCPConnection connection)
{
	while (true)
	{

		std::cout << "Please enter your message : \n";
		std::string input;
		getline(std::cin, input);
		const char* input1 = input.c_str();
		connection.Send(const_cast<char*>(input1));
	}
}

void terminal::ListenInputUDP(UDPConnection connection, int port, char* adresse)
{
	while (true)
	{
		std::cout << "Please enter your message : \n";
		std::string input;
		getline(std::cin, input);
		const char* input1 = input.c_str();
		connection.Send(const_cast<char*>(input1), port, adresse);
	}
}
