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


void createUniverseFile::getRules(std::string& rules, std::vector<int>& born, std::vector<int>& survive) {
    size_t pos = 0;

    if (rules.find("#R") == std::string::npos) {
        std::cout << "Please, enter the rules of game: " << std::endl;
        std::cin >> rules;
    }

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

const std::string createUniverseFile::getName(std::string& str) {
    //std::string name = str;
    if (/*str.empty() or */str.find("#N") == std::string::npos) {
        std::cout << "Please, enter the name of universe: " << std::endl;
        std::cin >> str;
    }
    while (isspace(str.front()) or str.front() == '#' or str.front() == 'N') {
        str.erase(0, 1);
    }
    while (isspace(str.back())) {
        str.erase(str.length() - 1, 1);
    }
    return str;
}

createUniverseFile::createUniverseFile(std::ifstream& fin) : fin(fin) {}

Universe createUniverseFile::create() {
    std::string format;
    std::string name;
    std::string rules;
    std::string saved;

    format = readLine();
    if (format.find("#N") != std::string::npos) {
        name = std::move(format);
    }

    if (name.empty()) {
        name = readLine();
    }
    if (name.find("#R") != std::string::npos) {
        rules = std::move(name);
    }
    name = getName(name);

    if (rules.empty()) {
        rules = readLine();
    }
    if (rules.find("#R") == std::string::npos) {
        saved = std::move(rules);
    }
    std::vector<int> born;
    std::vector<int> survive;
    getRules(rules, born, survive);


    Universe newUniverse(name, born, survive);

    int x;
    int y;

    if (!saved.empty()) {
        int pos = 0;
        std::string coord;
        while (pos < saved.length() and !isDigit(saved[pos])) {
            ++pos;
        }
        while (pos < saved.length() and isDigit(saved[pos])) {
            coord += saved[pos];
            ++pos;
        }
        x = stoi(coord);
        coord.clear();

        while (pos < saved.length() and !isDigit(saved[pos])) {
            ++pos;
        }
        while (pos < saved.length() and isDigit(saved[pos])) {
            coord += saved[pos];
            ++pos;
        }
        y = stoi(coord);
    }

    while (fin >> x >> y) {
        newUniverse.setCell(x - 1, y - 1, true);
    }

    return newUniverse;
}

