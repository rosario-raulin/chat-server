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
	void addClient(int fd);
	void remClient(int fd);
	ServerSocket* getServer();
	vector<string>* getClients();
	void sendToAll(Client* from, string& message);
	void sendTo(string& to, string& message);
	void sendTo(Client* to, string& message);
	bool inUse(string& name);
	void rename(Client* cl, string to);

private:
	ServerSocket* _server;
	map<int,Client*> _clients;
	map<string,Client*> _names;

	string _genRandomName();
	vector<struct pollfd> *_getPollFds();
};

#endif /* CHATSERVER_H_ */
