/*
 * main.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "ChatServer.h"
#include <iostream>
#include <signal.h>
#include <cstring>
#include <cstdlib>

using namespace std;

static int socket = -1;

void printUsage(const char* appName) {
	cout << "usage: " << appName << " port" << endl;
}

void handle_kill(int s) {
	if (socket > 0) {
		close(socket);
		socket = -1;
	}
	cout << "signal handler called" << endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = &handle_kill;
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGKILL, &sa, NULL);

	if (argc > 1) {
		try {
			ChatServer server(argv[1]);
			socket = server.getServer()->getFd();
			server.run();
		} catch (const char* &e) {
			cerr << e << endl;
			return EXIT_FAILURE;
		}
		return 0;
	} else {
		printUsage(argv[0]);
		return EXIT_FAILURE;
	}
}

