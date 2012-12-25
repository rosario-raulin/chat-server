/*
 * ListCommand.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "ListCommand.h"
#include <sstream>
#include <iostream>

ListCommand::ListCommand(Client* from) : Command(from) {
}

ListCommand::~ListCommand() {
}

void ListCommand::execute(ChatServer *cs) {
	ostringstream msg;
	vector<string>* clients = cs->getClients();
	for (vector<string>::iterator i = clients->begin();
			i != clients->end();
			++i) {
		msg << *i << endl;
	}
	string list = msg.str();
	cs->sendTo(_from, list);
	delete clients;
}
