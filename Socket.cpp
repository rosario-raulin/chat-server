/*
 * Socket.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "Socket.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>

Socket::Socket(int fd) {
	_fd = fd;
}

int Socket::getFd() {
	return _fd;
}

int Socket::readTo(ostringstream& to) {
	char buf[BUFSIZE];
	int bytes_written = read(_fd, buf, BUFSIZE-1);
	if (bytes_written > 0) {
		buf[bytes_written] = '\0';
		to << buf;
	}
	return bytes_written;
}

void Socket::write(string& message) {
	if (send(_fd, message.data(), message.size(), MSG_NOSIGNAL) == -1) {
		// TODO: throw more appropriate exception
		throw "write failed";
	}
}

void Socket::shutdown() {
	if (_fd > 0) {
		close(_fd);
		cout << "closed: " << _fd << endl;
		_fd = -1;
	}
}

Socket::~Socket() {
	cout << "called ~Socket()" << endl;
	cout << _fd << endl;
	shutdown();
}
