/*
 * main.cpp
 *
 *  Created on: 24.12.2012
 *      Author: rosario
 */

#include "ChatServer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void printUsage(const char* appName) {
	cout << "usage: " << appName << " port" << endl;
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		try {
			ChatServer server(argv[1]);
			server.run();
		} catch (const char* &e) {
			cerr << e << endl;
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	} else {
		printUsage(argv[0]);
		return EXIT_FAILURE;
	}
}

