#include "createUniverseFile.h"
#include "createUniverse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Universe.h"

std::string createUniverseFile::readLine() {
    std::string data;
    std::getline(fin, data);
    return data;
}

void createUniverseFile::readRules(const std::string& rules, std::vector<int>& born, std::vector<int>& survive) {
    size_t pos = 0;

    while (pos < rules.length() and rules[pos] != 'B' and rules[pos] != 'b') {
        ++pos;
    }
    ++pos;

    while (pos < rules.length() and rules[pos] >= '0' and rules[pos] <= '8') {
        born.push_back(rules[pos] - '0');
        ++pos;
    }

    while (pos < rules.length() and rules[pos] != 'S' and rules[pos] != 's') {
        ++pos;
    }
    ++pos;

    while (pos < rules.length() and rules[pos] >= '0' and rules[pos] <= '8') {
        survive.push_back(rules[pos] - '0');
        ++pos;
    }
}

createUniverseFile::createUniverseFile(std::ifstream& fin) : fin(fin) {}

Universe createUniverseFile::create() {
    std::string format = readLine();
    std::string name = readLine();
    std::string rules = readLine();

    std::vector<int> born;
    std::vector<int> survive;
    readRules(rules, born, survive);

    Universe newUniverse(name, born, survive);

    int x;
    int y;
    while (fin >> x >> y) {
        newUniverse.setCell(x - 1, y - 1, true);
    }

    return newUniverse;
}

