/*
 * Command.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Client.h"
#include "ChatServer.h"

class Client;
class ChatServer;

class Command {
public:
	Command(Client* from) : _from(from) {};
	virtual ~Command() {};
	virtual void execute(ChatServer* cs) = 0;

protected:
	Client* _from;
};

#endif /* COMMAND_H_ */
