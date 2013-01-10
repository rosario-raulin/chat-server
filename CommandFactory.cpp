/*
 * CommandFactory.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "CommandFactory.h"
#include "PublicMessage.h"
#include "PrivateMessage.h"
#include "ListCommand.h"
#include "NickCommand.h"
#include "UnknownCommand.h"
#include <sys/types.h>
#include <regex.h>
#include <cstring>

CommandFactory::CommandFactory() {
}

CommandFactory::~CommandFactory() {
}

bool CommandFactory::_matches(const string& input, const char* regex) {
	regex_t preg;
	if (regcomp(&preg, regex, REG_NOSUB) == 0) {
		return regexec(&preg, input.c_str(),0, NULL, 0) == 0;
	}
	return false;
}

Command* CommandFactory::createInstance(Client* from, const string& msg) {
	Command* cmd = NULL;

	if(msg[0] == '/') {
		if (_matches(msg, "/list")) {
			cmd = new ListCommand(from);
		} else if (_matches(msg, "/msg [[:alnum:]]\\+ [[:alnum:]]\\+")) {
			size_t name_start = msg.find(' ')+1;
			size_t text_start = msg.find(' ', name_start);
			string name = msg.substr(name_start, text_start - name_start);
			string text = msg.substr(text_start+1);
			cmd = new PrivateMessage(from, name, text);
		} else if (_matches(msg, "/nick [[:alnum:]]\\+")) {
			size_t nick_start = msg.find(' ')+1;
			size_t nick_end = msg.find(' ', nick_start);
			if (nick_end == string::npos) {
				nick_end = msg.length()-1;
			}
			string nick = msg.substr(nick_start, nick_end - nick_start);
			cmd = new NickCommand(from, nick);
		} else {
			cmd = new UnknownCommand(from);
		}
	} else {
		cmd = new PublicMessage(from, msg);
	}
	return cmd;
}
