#include "createUniverseGenerator.h"
#include "createUniverse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "Universe.h"


Universe createUniverseGenerator::create() {
    srand(time(NULL));
    std::string name = "RandomUniverse";

    std::vector<int> born;
    std::vector<int> survive;

    int numberOfBornRules = rand() & 9;
    int numberOfSurviveRules = rand() & 9;

    for (int i = 0; i < numberOfBornRules; ++i) {
        born.push_back(rand() % 9);
    }

    for (int i = 0; i < numberOfSurviveRules; ++i) {
        survive.push_back(rand() % 9);
    }

    int sizeX = rand() % 30;
    int sizeY = rand() % 90;

    Universe newUniverse(sizeX, sizeY, name, born, survive);
    newUniverse.setName(name);

    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            int x = rand() % 2;
            if (x == 1) {
                newUniverse.setCell(i, j, true);
            }
            else {
                newUniverse.setCell(i, j, false);
            }
        }
    }
    return newUniverse;
}

