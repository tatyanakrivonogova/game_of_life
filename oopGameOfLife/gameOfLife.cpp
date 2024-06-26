#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Universe.h"
#include "creatorFactory.h"
#include "createUniverse.h"
#include "createUniverseFile.h"
#include "createUniverseGenerator.h"
#include "showerFactory.h"
#include "showUniverse.h"
#include "showUniverseConsole.h"
#include "showUniverseFile.h"
#include "runnerFactory.h"
#include "runLife.h"
#include "runLifeOnline.h"
#include "runLifeOffline.h"
#include "runLifeCmd.h"

void getAnswer(std::string& str) {
	std::cin >> str;
	while (isspace(str.front())) {
		str.erase(0, 1);
	}
	while (isspace(str.back())) {
		str.erase(str.length() - 1, 1);
	}
	std::transform(str.begin(), str.end(), str.begin(), tolower);
	checkExit(str);
}

bool checkFileFormat(std::string& str) {
	checkExit(str);
	std::string format;

	while (isspace(str.front())) {
		str.erase(0, 1);
	}
	while (isspace(str.back())) {
		str.erase(str.length() - 1, 1);
	}

	std::string::iterator pos = find(str.begin(), str.end(), '.');
	if (pos == str.end()) {
		std::cout << "Wrong name of file. Please, try again: " << std::endl;
		return 1;
	}
	++pos;
	while (pos != str.end()) {
		format += (*pos);
		++pos;
	}
	if (format == "life" or format == "txt") {
		return 0;
	} else {
		std::cout << "Wrong name of file. Please, try again: " << std::endl;
		return 1;
	}
}

bool openFile(std::ifstream& fin, std::string& fileName) {
	fin.open(fileName);
	if (fin.fail()) {
		std::cout << "This file is not available. Try again: " << std::endl;
		return 1;
	}
	return 0;
}

void checkExit(std::string& str) {
	if (str == "exit") {
		std::cout << "Game over!" << std::endl;
		exit(0);
	}
}

bool isDigit(char c) {
	return c >= '0' and c <= '9';
}

std::string getCmdArgument(std::string& str) {
	while (isspace(str.front())) {
		str.erase(0, 1);
	}
	while (isspace(str.back())) {
		str.erase(str.length() - 1, 1);
	}
	return str;
}

const std::string getIterations(const std::string& str) {
	size_t pos = str.find('=');
	++pos;
	while (pos < str.length() and isspace(str[pos])) {
		++pos;
	}
	std::string iterations;
	while (pos < str.length()) {
		iterations += str[pos];
		++pos;
	}
	return iterations;
}

bool checkIterations(std::string& str) {
	std::string iterations;

	while (isspace(str.front())) {
		str.erase(0, 1);
	}
	while (isspace(str.back())) {
		str.erase(str.length() - 1, 1);
	}
	if (str.empty()) {
		std::cout << "Wrong iterations argument. Please, try again: " << std::endl;
		return 1;
	}
	for (auto symbol : str) {
		if (!isDigit(symbol)) {
			std::cout << "Wrong iterations argument. Please, try again: " << std::endl;
			return 1;
		}
	}
	return 0;
}

const std::string getFile(const std::string& str) {
	size_t pos = str.find('=');
	++pos;
	while (pos < str.length() and isspace(str[pos])) {
		++pos;
	}
	std::string outputFile;
	while (pos < str.length() and !isspace(str[pos])) {
		outputFile += str[pos];
		++pos;
	}
	return outputFile;
}

/*
int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");

	creatorFactory creatorFactory;
	runnerFactory runnerFactory;

	std::string inputFile;
	std::ifstream fin;

	if (argc >= 2) {
		inputFile = argv[1];

		while (checkFileFormat(inputFile) == 1 or openFile(fin, inputFile) == 1) {
			std::cin >> inputFile;
		}
	}

	if (argc > 2) {
		std::string commandTemplate1 = "--iterations=";
		std::string commandTemplate2 = "--output=";

		std::string outputFile;
		int numberOfIterations;
		int currentArgument = 2;

		while (currentArgument < argc) {
			std::string argument = argv[currentArgument];
			std::string command = getCmdArgument(argument);

			if (command == "-i") {
				++currentArgument;
				std::string iterations = argv[currentArgument];
				while (checkIterations(iterations) == 1) {
					std::cin >> iterations;
				}
				numberOfIterations = stoi(iterations);
			}

			else if (command == "-o") {
				outputFile = argv[++currentArgument];
				while (checkFileFormat(outputFile) == 1) {
					std::cin >> outputFile;
				}
			}

			else if (command.find(commandTemplate1) != std::string::npos) {
				std::string iterations = getIterations(command);
				while (checkIterations(iterations) == 1) {
					std::cin >> iterations;
				}
				numberOfIterations = stoi(iterations);
			}

			else if (command.find(commandTemplate2) != std::string::npos) {
				outputFile = getFile(command);
				while (checkFileFormat(outputFile) == 1) {
					std::cin >> outputFile;
				}
			}
			else {
				std::cout << command << " " << "Wrong argument. Game over!" << std::endl;
				exit(0);
			}
			++currentArgument;
		}
		std::ofstream fout(outputFile);

		std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(file, &fin);
		Universe newUniverse = creator->create();
		std::shared_ptr<runLife> runner = runnerFactory.buildRunner(cmd, &newUniverse, &fout, numberOfIterations);
		runner->run();

		exit(0);
	}

	std::string option;
	std::cout << "Choose the option: " << std::endl;
	std::cout << "Enter 'online' or 'offline' : " << std::endl;
	getAnswer(option);


	while (option != "offline" and option != "online") {
		std::cout << "Wrong input command. Please, try again: " << std::endl;
		getAnswer(option);
	}

	if (option == "offline") {
		if (inputFile.empty()) {
			std::cout << "Enter the name of input file in '*.life' or '*.txt' format: " << std::endl;
			std::cin >> inputFile;
			while (checkFileFormat(inputFile) == 1 or openFile(fin, inputFile) == 1) {
				std::cin >> inputFile;
			}
		}

		std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(file, &fin);
		Universe newUniverse = creator->create();
		std::shared_ptr<runLife> runner = runnerFactory.buildRunner(offline, &newUniverse);
		runner->run();
	}

	if (option == "online") {
		std::string option1;
		std::cout << "Do you want to generate universe or read it from file? " << std::endl;
		std::cout << "Enter 'generate' or 'read': " << std::endl;
		getAnswer(option1);
		while (option1 != "read" and option1 != "generate") {
			std::cout << "Wrong input command. Please, try again: " << std::endl;
			getAnswer(option1);
		}

		if (option1 == "generate") {
			std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(generator);
			Universe newUniverse = creator->create();
			std::shared_ptr<runLife> runner = runnerFactory.buildRunner(online, &newUniverse);
			runner->run();
		}

		if (option1 == "read") {
			if (inputFile.empty()) {
				std::cout << "Enter the name of input file in '*.life' or '*.txt' format: " << std::endl;
				std::cin >> inputFile;
				while (checkFileFormat(inputFile) == 1 or openFile(fin, inputFile) == 1) {
					std::cin >> inputFile;
				}
			}
			std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(file, &fin);
			Universe newUniverse = creator->create();
			std::shared_ptr<runLife> runner = runnerFactory.buildRunner(online, &newUniverse);
			runner->run();
		}
	}
	return 0;
}
*/