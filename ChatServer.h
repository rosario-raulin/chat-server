/*
 * ChatServer.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef CHATSERVER_H_
#define CHATSERVER_H_

#include "Client.h"
#include "ServerSocket.h"
#include <poll.h>
#include <vector>
#include <map>

#define DEFAULT_NAME_LEN 20

class Client;

using namespace std;

class ChatServer {
public:
	ChatServer(const char* port);
	virtual ~ChatServer();

	void run();
	void addClient(const int fd);
	void remClient(const int fd);
	ServerSocket* getServer() const;
	vector<string>* getClients() const;
	void sendToAll(const Client * from, const string& message) const;
	void sendTo(const string& to, const string& message);
	void sendTo(const Client * to, const string& message) const;
	bool inUse(const string& name) const;
	void rename(Client * cl, const string& to);

private:
	ServerSocket * _server;
	map<int,Client*> _clients;
	map<string,Client*> _names;

	string _genRandomName();
	vector<struct pollfd> *_getPollFds();
};

#endif /* CHATSERVER_H_ */
