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
	Client(int fd, const string& name);
	virtual ~Client();

	string const& getName() const;
	Socket* getSocket() const;
	Command* getCommand();
	void setName(const string& name);
	bool readNext();

private:
	Socket* _socket;
	string _username;
	ostringstream _buffer;
	Command* _command;

	bool _hasCommand();
};

#endif /* CLIENT_H_ */
