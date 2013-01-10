/*
 * Client.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "Client.h"
#include <iostream>

Client::Client(int fd, const string& name) {
	_socket = new Socket(fd);
	_username = name;
	_command = NULL;
}

Client::~Client() {
	delete _socket;
}

string const& Client::getName() const {
	return _username;
}

Socket* Client::getSocket() const {
	return _socket;
}

void Client::setName(const string& name) {
	_username = name;
}

bool Client::readNext() {
	return _socket->readTo(_buffer) > 0;
}

bool Client::_hasCommand() {
	string s = _buffer.str();
	size_t pos = s.find('\n');
	if (pos != string::npos) {
		_command = CommandFactory::createInstance(this, s);
		_buffer.str("");
		return true;
	} else {
		return false;
	}
}

Command* Client::getCommand() {
	_hasCommand();
	Command* c = _command;
	_command = NULL;
	return c;
}
