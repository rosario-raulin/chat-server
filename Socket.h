/*
 * Socket.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <iostream>
#include <sstream>

#define BUFSIZE 8192

using namespace std;

class Socket {
public:
	Socket(int fd);
	virtual ~Socket();
	int getFd();
	int readTo(ostringstream& to);
	void write(string& message);
	void shutdown();

protected:
	int _fd;
};

#endif /* SOCKET_H_ */
