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

bool CommandFactory::_matches(const char* input, const char* regex) {
	regex_t preg;
	regmatch_t pmatch[1];
	if (regcomp(&preg, regex, 0) == 0) {
		return regexec(&preg, input, 1, pmatch, 0) == 0;
	}
	return false;
}

Command* CommandFactory::createInstance(Client* from, string& msg) {
	Command* cmd = NULL;

	if(msg[0] == '/') {
		if (_matches(msg.c_str(), "/list")) {
			cmd = new ListCommand(from);
		} else if (_matches(msg.c_str(), "/msg [[:alnum:]]\\+ [[:alnum:]]\\+")) {
			size_t name_start = msg.find(' ')+1;
			size_t text_start = msg.find(' ', name_start);
			string name = msg.substr(name_start, text_start - name_start);
			string text = msg.substr(text_start+1);
			cmd = new PrivateMessage(from, name, text);
		} else if (_matches(msg.c_str(), "/nick [[:alnum:]]\\+")) {
			size_t nick_start = msg.find(' ')+1;
			string nick = msg.substr(nick_start, msg.length() - nick_start -1);
			cmd = new NickCommand(from, nick);
		} else {
			cmd = new UnknownCommand(from);
		}
	} else {
		cmd = new PublicMessage(from, msg);
	}
	return cmd;
}
