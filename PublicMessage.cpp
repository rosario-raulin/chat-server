/*
 * PublicMessage.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "PublicMessage.h"
#include "Client.h"
#include <iostream>
#include <sstream>

PublicMessage::PublicMessage(Client* from, const string& message)
: Command(from) {
	ostringstream out;
	out << from->getName() << ": " << message << endl;
	_message = out.str();
}

PublicMessage::~PublicMessage() {
}

void PublicMessage::execute(ChatServer* cs) {
	cs->sendToAll(_from, _message);
}

