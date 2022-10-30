#include "runLifeCmd.h"
#include "runLife.h"
#include "Universe.h"
#include "showUniverse.h"
#include "showUniverseFile.h"
#include <iostream>
#include <string>



const std::string runLifeCmd::createRulesString() {
    std::string rules;
    rules += "#R B";
    for (auto x : currentUniverse.getBornRule()) {
        rules += x + '0';
    }
    rules += '/';
    rules += 'S';
    for (auto x : currentUniverse.getSurviveRule()) {
        rules += x + '0';
    }

    return rules;
}


const std::string runLifeCmd::createBornRule() {
    std::string bornRule;
    for (auto x : currentUniverse.getBornRule()) {
        bornRule += x + '0';
    }
    return bornRule;
}

const std::string runLifeCmd::createSurviveRule() {
    std::string surviveRule;
    for (auto x : currentUniverse.getSurviveRule()) {
        surviveRule += x + '0';
    }
    return surviveRule;
}

runLifeCmd::runLifeCmd(Universe& currentUniverse, std::ofstream& fout, int numberOfIterations) : runLife(currentUniverse), fout(fout), numberOfIterations(numberOfIterations){}

void runLifeCmd::run() {

    showUniverse* shower = new showUniverseFile(fout, currentUniverse);

    fout << "#Life 1.06" << std::endl;
    fout << "#N " << currentUniverse.getName() << std::endl;
    fout << createRulesString() << std::endl;

    for (int i = 0; i < currentUniverse.height(); ++i) {
        for (int j = 0; j < currentUniverse.width(); ++j) {
            checkRule(currentUniverse.torus(i, currentUniverse.height()), currentUniverse.torus(j, currentUniverse.width()));
        }
    }

    shower->show();
}

