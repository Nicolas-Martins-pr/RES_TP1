
#include "network.h"
#include <iostream>
#include <sstream>
#include <thread>

using namespace std;

int main() { 

	int protocol = 1;
	string ipAdress = "localhost";
	int port = 27000;
	cout << "CONFIGURATION OF THE SERVER\n";
	cout << "Please enter the protocol you want to use, 0 for UDP, 1 for TCP [ default 1 ] : \n";
	string input;
	getline(cin, input);
	if (!input.empty()) {
		istringstream stream(input);
		stream >> protocol;
	}

	cout << "Please enter the ip adress you want to use [ default localhost ] : \n";
	getline(cin, input);
	if (!input.empty()) {
		istringstream stream(input);
		stream >> ipAdress;
	}

	cout << "Please enter the port you want to use [ default 27000 ] : \n";
	getline(cin, input);
	if (!input.empty()) {
		istringstream stream(input);
		stream >> port;
	}
	cout << "Configured ! \n";


	//Create new Network
	network serverNetwork = network(protocol,ipAdress,port);


	
	return 0;
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
	
		// Echo the buffer back to the sender
	iSendResult = send(clientSocket, recvbuf, iResult, 0);
	if (iSendResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(clientSocket);
		WSACleanup();
		return 1;
	}

	puts("Data Sent\n");

	return 0;
}
*/