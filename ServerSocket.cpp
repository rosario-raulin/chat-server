/*
 * ServerSocket.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "ServerSocket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>

ServerSocket::ServerSocket(const char* port) : Socket(-1) {
	struct addrinfo hints, *res, *rp;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	if (getaddrinfo(NULL, port, &hints, &res) != 0) {
		// TODO: throw more appropriate exception
		throw "getaddrinfo() failed";
	} else {
		for (rp = res; rp != NULL; rp = rp->ai_next) {
			_fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
			if (_fd == -1) {
				continue;
			}
			if (bind(_fd, rp->ai_addr, rp->ai_addrlen) == 0) {
				break;
			}
		}
		freeaddrinfo(res);
		if (rp == NULL || listen(_fd, 3) != 0) {
			// TODO: throw more appropriate exception
			throw "could not bind to any port";
		}
	}
}

ServerSocket::~ServerSocket() {
}

