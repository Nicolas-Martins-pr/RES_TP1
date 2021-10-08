#include <iostream>
#include <sstream>

#include "network.h"

using namespace std;

int main() {


	int protocol = 1;
	string ipAdress = "localhost";
	int port = 27000;
	cout << "CONFIGURATION OF THE CLIENT\n";
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
	network clientNetwork = network(protocol, ipAdress, port);


	//CLEAN NEEDED 
	return 0;
}

//END OF SERVER