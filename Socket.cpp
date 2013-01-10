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

Socket::Socket(int fd) {
	_fd = fd;
}

int Socket::getFd() const {
	return _fd;
}

int Socket::readTo(ostringstream& to) const {
	char buf[BUFSIZE+1];
	int bytes_read = read(_fd, buf, BUFSIZE);
	if (bytes_read > 0) {
		buf[bytes_read] = '\0';
		to << buf;
	}
	return bytes_read;
}

void Socket::write(const string& message) const {
	if (send(_fd, message.data(), message.size(), MSG_NOSIGNAL) == -1) {
		// write failed
	}
}

void Socket::shutdown() {
	if (_fd > 0) {
		close(_fd);
		_fd = -1;
	}
}

Socket::~Socket() {
	shutdown();
}

