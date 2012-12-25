/*
 * NickCommand.h
 *
 *  Created on: 25.12.2012
 *      Author: rosario
 */

#ifndef NICKCOMMAND_H_
#define NICKCOMMAND_H_

#include "Command.h"
#include "ChatServer.h"

class NickCommand: public Command {
public:
	NickCommand(Client* from, const string& to);
	virtual ~NickCommand();

	void execute(ChatServer *cs);

protected:
	string _to;
};

#endif /* NICKCOMMAND_H_ */
