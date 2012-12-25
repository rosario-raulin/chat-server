/*
 * UnknownCommand.h
 *
 *  Created on: 25.12.2012
 *      Author: rosario
 */

#ifndef UNKNOWNCOMMAND_H_
#define UNKNOWNCOMMAND_H_

#include "Command.h"
#include "Client.h"
#include "ChatServer.h"

class UnknownCommand: public Command {
public:
	UnknownCommand(Client* from);
	virtual ~UnknownCommand();

	void execute(ChatServer* cs);
};

#endif /* UNKNOWNCOMMAND_H_ */
