#include "runLife.h"
#include "Universe.h"

runLife::runLife(Universe& currentUniverse) : currentUniverse(currentUniverse) {}

int runLife::checkRule(int i, int j)
{
    int lifeCount = 0;
    for (int k = i - 1; k < i + 2; ++k) {
        for (int n = j - 1; n < j + 2; ++n) {
            if (currentUniverse.getCell(k, n) == true) {
                lifeCount = lifeCount + 1;
            }
        }
    }
    if (currentUniverse.getCell(i, j) == true) {
        lifeCount = lifeCount - 1;
    }

    if (currentUniverse.getCell(i, j) == false) {

        for (auto bornValue : currentUniverse.getBornRule()) {
            if (lifeCount == bornValue) {
                currentUniverse.setCell(i, j, true);
                break;
            }
        }
    }
    else if (currentUniverse.getCell(i, j) == true) {

        bool flag = true;
        for (auto surviveValue : currentUniverse.getSurviveRule()) {
            if (lifeCount == surviveValue) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            currentUniverse.setCell(i, j, false);
        }


    }

    return currentUniverse.getCell(i, j);
}

