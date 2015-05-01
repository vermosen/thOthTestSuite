//============================================================================
// Name        : thOthTestSuite.cpp
// Author      : Jean-Mathieu Vermosen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>

#include <signalTest/signalTest1.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char** argv) {

	int exit;														// exit code

	try {

		bool end = false;											// main exit indicator
		int test = 0    ;											// optional test

		for (int i = 1; i < argc; i++) {							// deals with optional arguments

			std::string arg(argv[i]);								// current std::string

			if (arg.substr(1, 4) == "test") {						// expects -test=n

				std::string str(arg.substr(6, arg.length() - 6));	// the value
				test = boost::lexical_cast<int>(str);				// runs the selected test automatically
				end = true;											// for later use: only one attempt

			}
		}

		do {														// manual selection - loop over the choices

			int res = test;											// for manual definition

			if (test == 0) {

				std::cout											// message
					<< std::endl << "Please select an activity: "
					<< std::endl
					<< std::endl << "####### signals #######"
					<< std::endl
					<< std::endl << "#### miscellanous #####"
					<< std::endl << "0 - exit"
					<< std::endl
					<< std::endl;

				std::cin >> res;									// user defined test

			}

			switch (res) {											// switch over the available tests

			case 1:

				signalTest1();
				break;

			case 0:

				end = true;											// stop the server
				break;

			default:												// unknown, invalid

				std::cout
					<< "invalid selection, please try again"
					<< std::endl;

				break;

			}

		} while (end == false);										// loop until exit

		exit = 0;

	}
	catch (std::exception & e) {									// exception management

		std::cout
			<< "an error occurred: "
			<< e.what()
			<< std::endl;

		exit = 1; system("pause");

	}
	catch (...) {													// unknown error

		std::cout
			<< "an unknown error occurred..."
			<< std::endl;

		exit = 1; system("pause");

	}

	std::cout
		<< std::endl
		<< "Goodbye !!"
		<< std::endl;

	return exit;

}
