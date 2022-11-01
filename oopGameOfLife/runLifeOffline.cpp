#include "runLifeOffline.h"
#include "runLife.h"
#include "Universe.h"
#include "showUniverse.h"
#include "showUniverseFile.h"
#include "showUniverseConsole.h"
#include <iostream>
#include <string>

extern bool checkIterations(std::string&);

const std::string runLifeOffline::createBornRule() {
    std::string bornRule;
    for (auto x : currentUniverse->getBornRule()) {
        bornRule += x + '0';
    }
    return bornRule;
}

const std::string runLifeOffline::createSurviveRule() {
    std::string surviveRule;
    for (auto x : currentUniverse->getSurviveRule()) {
        surviveRule += x + '0';
    }
    return surviveRule;
}

runLifeOffline::runLifeOffline(Universe* currentUniverse) : runLife(currentUniverse) {}

void runLifeOffline::run() {

    std::string command;

    std::cout << "Enter next command: " << std::endl;
    getAnswer(command);
    while (command.length() != 0) {
        while (command != "tick" and command != "dump" and command != "help" and command != "exit") {
            std::cout << "Wrong input command. Please, try again: " << std::endl;
            getAnswer(command);
        }
        if (command == "tick") {

            std::cout << "Enter the number of iterations: " << std::endl;
            std::string iterations;
            std::cin >> iterations;
            while (checkIterations(iterations) == 1) {
                std::cin >> iterations;
            }
            numberOfIterations = stoi(iterations);

            
            std::cout << "Name of Universe: " << currentUniverse->getName() << std::endl;
            std::cout << "The cell will be borned if number of alive cells around is equal: " << createBornRule() << std::endl;
            std::cout << "The cell will survive if number of alive cells around is equal: " << createSurviveRule() << std::endl;
            std::cout << "Current iteration: " << numberOfIterations << std::endl;

            for (int i = 0; i < numberOfIterations; ++i) {
                changeUniverse();
            }

            showUniverse* shower = new showUniverseConsole(currentUniverse);
            shower->show(); // sleep and expect any click
        }

        if (command == "dump") {
            std::string outputFile;

            std::cout << "Enter the name of output file in '*.life' or '*.txt' format: " << std::endl;
            std::cin >> outputFile;
            while (checkFileFormat(outputFile) == 1) {
                std::cin >> outputFile;
            }
            std::ofstream fout(outputFile);
            showUniverse* shower = new showUniverseFile(&fout, currentUniverse);

            shower->show();
        }

        if (command == "exit") {
            std::cout << "Game over!" << std::endl;
            exit(0);
        }

        if (command == "help") {
            std::cout << "Enter one of the following commands" << std::endl;
            std::cout << "  'dump <filename>':       save the universe to a file" << std::endl;
            std::cout << "  'tick <n>':              run n iterations and print the result" << std::endl;
            std::cout << "  'exit':                  finish the game" << std::endl;
        }

        std::cout << "Enter some command: " << std::endl;
        std::cin >> command;
    }

}

