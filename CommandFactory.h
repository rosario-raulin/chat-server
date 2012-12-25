/*
 * CommandFactory.h
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#ifndef COMMANDFACTORY_H_
#define COMMANDFACTORY_H_

#include "Client.h"
#include "Command.h"
#include <string>

class Client;
class Command;

using namespace std;

class CommandFactory {
public:
	CommandFactory();
	virtual ~CommandFactory();

	static Command* createInstance(Client* from, const string& msg);

private:
	static bool _matches(const string& input, const char* regex);
};

#endif /* COMMANDFACTORY_H_ */
