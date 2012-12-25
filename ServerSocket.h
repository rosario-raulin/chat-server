/*
 * ServerSocket.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef SERVERSOCKET_H_
#define SERVERSOCKET_H_

#include "Socket.h"

class ServerSocket: public Socket {
public:
	ServerSocket(const char* port);
	virtual ~ServerSocket();
};

#endif /* SERVERSOCKET_H_ */
