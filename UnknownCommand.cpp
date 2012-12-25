/*
 * UnknownCommand.cpp
 *
 *  Created on: 25.12.2012
 *      Author: rosario
 */

#include "UnknownCommand.h"

UnknownCommand::UnknownCommand(Client* from) : Command(from) {
}

UnknownCommand::~UnknownCommand() {
}

void UnknownCommand::execute(ChatServer *cs) {
	string errMsg("error: unknown command\n");
	cs->sendTo(_from, errMsg);
}

