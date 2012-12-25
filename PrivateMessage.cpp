/*
 * PrivateMessage.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "PrivateMessage.h"

PrivateMessage::PrivateMessage(Client* from, const string& to, const string& message)
: PublicMessage(from, message) {
	_to = to;
}

void PrivateMessage::execute(ChatServer *cs) {
	cs->sendTo(_to, _message);
}

PrivateMessage::~PrivateMessage() {
}

