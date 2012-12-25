/*
 * ListCommand.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef LISTCOMMAND_H_
#define LISTCOMMAND_H_

#include "Command.h"
#include "Client.h"
#include "ChatServer.h"

class ListCommand: public Command {
public:
	ListCommand(Client* from);
	virtual ~ListCommand();

	void execute(ChatServer* cs);
};

#endif /* LISTCOMMAND_H_ */
