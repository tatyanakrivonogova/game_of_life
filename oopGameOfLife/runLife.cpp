#include "runLife.h"
#include "Universe.h"

runLife::runLife(Universe* currentUniverse) : currentUniverse(currentUniverse) {}

bool runLife::checkRule(int i, int j)
{
    int lifeCount = 0;
    for (int k = i - 1; k < i + 2; ++k) {
        for (int n = j - 1; n < j + 2; ++n) {
            if (currentUniverse->getCell(k, n) == true) {
                lifeCount = lifeCount + 1;
            }
        }
    }
    if (currentUniverse->getCell(i, j) == true) {
        lifeCount = lifeCount - 1;
    }

    if (currentUniverse->getCell(i, j) == false) {

        for (auto bornValue : currentUniverse->getBornRule()) {
            if (lifeCount == bornValue) {
                return true;
            }
        }
    }
    else if (currentUniverse->getCell(i, j) == true) {

        for (auto surviveValue : currentUniverse->getSurviveRule()) {
            if (lifeCount == surviveValue) {
                return true;
            }
        }
    }

    return false;
}

void runLife::changeUniverse() {
    std::vector< std::vector<bool> > newcells;
    newcells.resize(currentUniverse->width());
    for (int i = 0; i < currentUniverse->width(); ++i) {
        newcells[i].resize(currentUniverse->height());
        for (int j = 0; j < currentUniverse->height(); ++j) {
            newcells[i][j] = checkRule(currentUniverse->torus(i, currentUniverse->width()), currentUniverse->torus(j, currentUniverse->height()));
        }
    }
    currentUniverse->changeCells(std::move(newcells));
}