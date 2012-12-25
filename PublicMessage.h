/*
 * PublicMessage.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef PUBLICMESSAGE_H_
#define PUBLICMESSAGE_H_

#include "Command.h"
#include "Client.h"
#include <string>

using namespace std;

class PublicMessage: public Command {
public:
	PublicMessage(Client* from, const string& message);
	virtual ~PublicMessage();

	void execute(ChatServer* cs);

protected:
	string _message;
};

#endif /* PUBLICMESSAGE_H_ */
