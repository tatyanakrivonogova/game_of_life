#include "createUniverseGenerator.h"
#include "createUniverse.h"
#include "createUniverseFile.h"
#include "creatorFactory.h"
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
    creatorFactory creatorFactory;
    std::ifstream fin;

    if (number == 0) {
        fin.open("gosper_glider_gun.txt");
        
    }
    if (number == 1) {
        fin.open("clock.txt");
    }
    if (number == 2) {
        fin.open("endless_growth.txt");
    }
    if (number == 3) {
        fin.open("galaxy.txt");
    }
    if (number == 4) {
        fin.open("oktagon2.txt");
    }
    if (number == 5) {
        fin.open("pi-wave.txt");
    }
    if (number == 6) {
        fin.open("pulsar.txt");
    }
    if (number == 7) {
        fin.open("planer.txt");
    }
    if (number == 8) {
        fin.open("random_exploration.txt");
    }
    if (number == 9) {
        fin.open("star.txt");
    }
    if (number == 10) {
        fin.open("space_ship.txt");
    }
    if (number == 11) {
        fin.open("penta.txt");
    }

    //createUniverse* creator = new createUniverseFile(&fin);
    std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(file, &fin);
    newUniverse = creator->create();

    return newUniverse;
}

