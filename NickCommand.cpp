/*
 * NickCommand.cpp
 *
 *  Created on: 25.12.2012
 *      Author: rosario
 */

#include "NickCommand.h"

NickCommand::NickCommand(Client* from, const string& to) : Command(from) {
	_to = to;
}

NickCommand::~NickCommand() {
}

void NickCommand::execute(ChatServer *cs) {
	if (cs->inUse(_to)) {
		string errMsg("error: username already in use!\n");
		cs->sendTo(_from, errMsg);
	} else {
		cs->rename(_from, _to);
	}
}

