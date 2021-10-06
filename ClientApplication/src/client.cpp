#include <iostream>

#include "network.h"

using namespace std;

int main() {

	int protocol;
	string ipAdress;
	int port;
	std::cout << "CONFIGURATION OF THE CLIENT\n";
	cout << "Please enter the protocol you want to use, 0 for UDP, 1 for TCP : \n";
	cin >> protocol;
	cout << "Please enter the ip adress you want to use : \n";
	cin >> ipAdress;
	cout << "Please enter the port you want to use : \n";
	cin >> port;
	cout << "Configured ! \n";

	//Create new Network
	network clientNetwork = network(protocol, ipAdress, port);


	//CLEAN NEEDED 
	//return 0;
}

//END OF SERVER


/*
	//send some data 
	message = (char*)"test";
	if (send(clientSocket, message, (int) strlen(message), 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");

	//receive some data
	if (recv_size = recv(s, server_reply, 2000, 0) == SOCKET_ERROR)
	{
		puts("recv failed");
	}
	puts ("Reply received\n");

	//Add a NULL terminating character to make it a proper string before printing
	server_reply[recv_size] = '\0';
	puts(server_reply);

	
	//On reçoit nos données
	char* buffer = (char*)malloc(1024 * sizeof(char));
	recv(clientSocket, buffer, 1024, 0);
	free(buffer);

	//On envoie des données
	char* buffer2 = (char*)malloc(1024 * sizeof(char));
	send(clientSocket, buffer2, 1024, 0);
	free(buffer2);
	

	return 0;
}*/
