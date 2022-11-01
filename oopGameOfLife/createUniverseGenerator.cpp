#include "createUniverseGenerator.h"
#include "createUniverse.h"
#include "createUniverseFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "Universe.h"


Universe createUniverseGenerator::create() {
    /*srand(time(NULL));
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
    }*/

    srand(time(NULL));
    int number = rand() % 12;
    Universe newUniverse;

    if (number == 0) {
        std::ifstream fin("gosper_glider_gun.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 1) {
        std::ifstream fin("clock.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 2) {
        std::ifstream fin("endless_growth.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 3) {
        std::ifstream fin("galaxy.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 4) {
        std::ifstream fin("oktagon2.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 5) {
        std::ifstream fin("pi-wave.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 6) {
        std::ifstream fin("pulsar.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 7) {
        std::ifstream fin("planer.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 8) {
        std::ifstream fin("random_exploration.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 9) {
        std::ifstream fin("star.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 10) {
        std::ifstream fin("space_ship.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }
    if (number == 11) {
        std::ifstream fin("penta.txt");
        createUniverse* creator = new createUniverseFile(&fin);
        newUniverse = creator->create();
    }

    return newUniverse;
}

