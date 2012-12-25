/*
 * PrivateMessage.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef PRIVATEMESSAGE_H_
#define PRIVATEMESSAGE_H_

#include "PublicMessage.h"

class PrivateMessage : public PublicMessage {
public:
	PrivateMessage(Client* from, const string& to, const string& message);
	virtual ~PrivateMessage();

	void execute(ChatServer* cs);

private:
	string _to;
};

#endif /* PRIVATEMESSAGE_H_ */
