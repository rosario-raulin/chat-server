/*
 * Client.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Command.h"
#include "CommandFactory.h"
#include "Socket.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Client {
public:
	Client(int fd, string name);
	virtual ~Client();

	string getName();
	Socket* getSocket();
	Command* getCommand();
	void setName(string name);
	bool readNext();

private:
	Socket* _socket;
	string _username;
	ostringstream _buffer;
	Command* _command;

	bool _hasCommand();
};

#endif /* CLIENT_H_ */
