/*
 * ChatServer.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "ChatServer.h"
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>

ChatServer::ChatServer(const char* port) {
	_server = new ServerSocket(port);
}

ChatServer::~ChatServer() {
	delete _server;
	for (map<int,Client*>::iterator i = _clients.begin();
			i != _clients.end();
			++i) {
		delete i->second;
	}
}

void ChatServer::run() {
	while (true) {
		vector<struct pollfd>* fds = _getPollFds();
		int revents = poll(fds->data(), fds->size(), -1);
		int handled = 0;
		for (vector<struct pollfd>::iterator i = fds->begin();
				i != fds->end() && handled < revents;
				++i) {
			if (i->revents != 0) {
				++handled;
				if (i->fd == _server->getFd()) {
					// cout << "add new client" << endl;
					addClient(accept(_server->getFd(), NULL, NULL));
				} else {
					Client* c = _clients[i->fd];
					if (c->readNext() == false) {
						remClient(c->getSocket()->getFd());
						// cout << "removed old client" << endl;
					} else {
						Command* cmd = c->getCommand();
						if (cmd != NULL) {
							// cout << "execute command" << endl;
							cmd->execute(this);
						}
					}
				}
			}
		}
		delete fds;
	}
}

void ChatServer::addClient(int fd) {
	Client* next = new Client(fd, _genRandomName());
	_clients.insert(pair<int, Client*>(fd, next));
	_names.insert(pair<string, Client*>(next->getName(), next));
}

void ChatServer::remClient(int fd) {
	Client* x = _clients[fd];
	_clients.erase(fd);
	_names.erase(x->getName());
	delete x;
}

void ChatServer::sendToAll(Client* from, string& message) {
	for (map<int,Client*>::iterator i = _clients.begin();
			i != _clients.end();
			++i) {
		if (i->second != from) {
			i->second->getSocket()->write(message);
		}
	}
}

void ChatServer::sendTo(Client* cl, string& message) {
	cl->getSocket()->write(message);
}

void ChatServer::sendTo(string& to, string& message) {
	Client* to_c = _names[to];
	if (to_c != NULL) {
		sendTo(to_c, message);
	}
}

ServerSocket* ChatServer::getServer() {
	return _server;
}

vector<string>* ChatServer::getClients() {
	vector<string>* clients = new vector<string>();
	clients->reserve(_clients.size());
	for (map<int,Client*>::iterator i = _clients.begin();
			i != _clients.end();
			++i) {
		clients->push_back(i->second->getName());
	}
	return clients;
}

bool ChatServer::inUse(string& name) {
	return _names.find(name) != _names.end();
}

void ChatServer::rename(Client *cl, string to) {
	_names.erase(cl->getName());
	cl->setName(to);
	_names.insert(pair<string,Client*>(to,cl));
}

vector<struct pollfd>* ChatServer::_getPollFds() {
	vector<struct pollfd> *clients = new vector<struct pollfd>(_clients.size()+1);
	for (map<int, Client*>::iterator i = _clients.begin();
			i != _clients.end();
			++i) {
		struct pollfd pfd = { i->second->getSocket()->getFd(), POLLIN, 0 };
		clients->push_back(pfd);
	}
	struct pollfd sfd = { _server->getFd(), POLLIN, 0 };
	clients->push_back(sfd);
	return clients;
}

string ChatServer::_genRandomName() {
	static const char ALPHABET[] =
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"1234567890";

	char buf[DEFAULT_NAME_LEN+1];
	buf[DEFAULT_NAME_LEN] = '\0';
	do {
		for (int i = 0; i < DEFAULT_NAME_LEN; ++i) {
			buf[i] = ALPHABET[rand() % sizeof(ALPHABET)];
		}
	} while(_names.find(buf) != _names.end());
	return string(buf);
}
