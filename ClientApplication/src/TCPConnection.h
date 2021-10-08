#ifndef RES_TP1_TCPCONNECTION_H
#define RES_TP1_TCPCONNECTION_H

#include "connection.h"

class TCPConnection : public Connection {

public:
	TCPConnection(SOCKET listenSocket, SOCKET connectSocket);
	char * Receive();
	void Send(char* message);
private:
};

#endif //RES_TP1_TCPCONNECTION_H
