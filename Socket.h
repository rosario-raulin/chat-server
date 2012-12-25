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
	int getFd() const;
	int readTo(ostringstream& to) const;
	void write(const string& message) const;
	void shutdown();

protected:
	int _fd;
};

#endif /* SOCKET_H_ */
