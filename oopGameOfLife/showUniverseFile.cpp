#include "showUniverseFile.h"
#include "showUniverse.h"
#include <iostream>
#include <fstream>


const std::string showUniverseFile::createBornRule() {
    std::string bornRule;
    for (auto x : currentUniverse->getBornRule()) {
        bornRule += x + '0';
    }
    return bornRule;
}

const std::string showUniverseFile::createSurviveRule() {
    std::string surviveRule;
    for (auto x : currentUniverse->getSurviveRule()) {
        surviveRule += x + '0';
    }
    return surviveRule;
}

const std::string showUniverseFile::createRulesString() {
    std::string rules;
    rules += "#R B";
    for (auto x : currentUniverse->getBornRule()) {
        rules += x + '0';
    }
    rules += '/';
    rules += 'S';
    for (auto x : currentUniverse->getSurviveRule()) {
        rules += x + '0';
    }

    return rules;
}

showUniverseFile::showUniverseFile(std::ofstream* fout, Universe* currentUniverse) : fout(fout), showUniverse(currentUniverse) {}

void showUniverseFile::show() {
	*fout << "#Life 1.06" << std::endl;
	*fout << "#N " << currentUniverse->getName() << std::endl;
	*fout << createRulesString() << std::endl;

	for (int i = 0; i < currentUniverse->width(); ++i) {
		for (int j = 0; j < currentUniverse->height(); ++j) {
			if (currentUniverse->getCell(i, j) == true) {
				*fout << i + 1 << " " << j + 1 << std::endl;
			}
		}
	}
}