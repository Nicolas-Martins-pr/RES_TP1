#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

int main() { 
	
	WSADATA wsaData;
	int iResult, iSendResult;
	SOCKET s, clientSocket;
	int recv_size;
	char recvbuf[256];
	int recvbuflen = 256;
	char * server_reply[2000];

	//Initialise Winsock
	printf("\nInitialising Winsock...");
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	printf("Initialised.\n");
	
	//Create socket TCP
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	printf("Socket created.\n");

	//On traduit nos données réseaux
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(80);
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

	//On va essayer de bind
	iResult = bind(s, (struct sockaddr*)&server, sizeof(server));
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	puts("Binded\n");

	//ACCEPT ET LISTEBN PAS UTILES POUR UDP
	//We tell the socket to listen (only ipv6)
	iResult = listen(s, 255);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	// Accept a client socket
	clientSocket = accept(s, NULL, NULL);
	if (clientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	// No longer need server socket
	closesocket(s);

	// Echo the buffer back to the sender
	iSendResult = send(clientSocket, recvbuf, iResult, 0);
	if (iSendResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(clientSocket);
		WSACleanup();
		return 1;
	}

	puts("Data Sent\n");
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
}
*/