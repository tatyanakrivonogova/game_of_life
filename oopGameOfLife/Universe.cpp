#include <string>
#include <vector>
#include "Universe.h"

Universe::Universe() : sizeX(0), sizeY(0) {}

Universe::Universe(std::string& name, std::vector<int>& born, std::vector<int>& survive) : sizeX(1), sizeY(1) {
    setName(name);
    cells.resize(1);
    std::vector<bool> subvector(1, false);
    cells[0] = subvector;

    bornRule = std::move(born);
    surviveRule = std::move(survive);

}


Universe::~Universe() {}


Universe::Universe(const Universe& otherUniverse) : sizeX(otherUniverse.sizeX), sizeY(otherUniverse.sizeY) {
    name = otherUniverse.name;

    cells.resize(sizeX);
    for (int i = 0; i < sizeX; ++i) {
        cells[i].resize(sizeY);
        for (int j = 0; j < sizeY; ++j) {
            cells[i][j] = otherUniverse.cells[i][j];
        }
    }

    bornRule.assign(otherUniverse.bornRule.begin(), otherUniverse.bornRule.end());
    surviveRule.assign(otherUniverse.surviveRule.begin(), otherUniverse.surviveRule.end());
}


Universe::Universe(Universe&& otherUniverse) noexcept : sizeX(otherUniverse.sizeX), sizeY(otherUniverse.sizeY) {
    setName(otherUniverse.name);
    cells = std::move(otherUniverse.cells);
    otherUniverse.sizeX = 0;
    otherUniverse.sizeY = 0;
    bornRule = std::move(otherUniverse.bornRule);
    surviveRule = std::move(otherUniverse.surviveRule);
}


Universe& Universe::operator=(const Universe& otherUniverse) {
    if (this == &otherUniverse)
        return *this;
    if (!cells.empty()) {
        for (int i = 0; i < sizeX; ++i) {
            cells[i].clear();
        }
        cells.clear();
    }
    name = otherUniverse.name;
    sizeX = otherUniverse.sizeX;
    sizeY = otherUniverse.sizeY;

    cells.resize(sizeX);
    for (int i = 0; i < sizeX; ++i) {
        cells[i].resize(sizeY);
        for (int j = 0; j < sizeY; ++j) {
            cells[i][j] = otherUniverse.cells[i][j];
        }
    }

    bornRule.assign(otherUniverse.bornRule.begin(), otherUniverse.bornRule.end());
    surviveRule.assign(otherUniverse.surviveRule.begin(), otherUniverse.surviveRule.end());
    return *this;
}


Universe& Universe::operator=(Universe&& otherUniverse) noexcept {
    if (this == &otherUniverse)
        return *this;
    if (!cells.empty()) {
        for (int i = 0; i < sizeX; ++i) {
            cells[i].clear();
        }
        cells.clear();
    }
    setName(otherUniverse.name);
    sizeX = otherUniverse.sizeX;
    sizeY = otherUniverse.sizeY;
    cells = std::move(otherUniverse.cells);
    otherUniverse.sizeX = 0;
    otherUniverse.sizeY = 0;
    bornRule = std::move(otherUniverse.bornRule);
    surviveRule = std::move(otherUniverse.surviveRule);
    return *this;
}

bool Universe::operator==(const Universe& other) {
    if (name != other.name) {
        return false;
    }

    if (bornRule != other.bornRule) {
        return false;
    }
    if (surviveRule != other.surviveRule) {
        return false;
    }

    if (sizeX != other.sizeX) {
        return false;
    }
    if (sizeY != other.sizeY) {
        return false;
    }

    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            if (cells[i][j] != other.cells[i][j]) {
                return false;
            }
        }
    }
    return true;
}


bool Universe::is_similar(const Universe& other) {

    if (bornRule != other.bornRule) {
        return false;
    }
    if (surviveRule != other.surviveRule) {
        return false;
    }

    int min_sizeX = std::min(sizeX, other.width());
    int min_sizeY = std::min(sizeY, other.height());


    for (int i = 0; i < min_sizeX; ++i) {
        for (int j = 0; j < min_sizeY; ++j) {
            if (cells[i][j] != other.cells[i][j]) {
                return false;
            }
        }
    }

    if (sizeX == min_sizeX) {
        for (int i = min_sizeX; i < other.width(); ++i) {
            for (int j = min_sizeY; j < other.height(); ++j) {
                if (other.cells[i][j] == true) {
                    return false;
                }
            }
        }
    }
    else {
        for (int i = min_sizeX; i < sizeX; ++i) {
            for (int j = min_sizeY; j < sizeY; ++j) {
                if (cells[i][j] == true) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Universe::setName(std::string& nameUniverse) {
    name = std::move(nameUniverse);
}

const std::string& Universe::getName() const {
    return name;
}

void Universe::setCell(int x, int y, bool value) {
    if (y > sizeY - 1) {
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < (y - sizeY + 1); ++j) {
                cells[i].push_back(false);
            }
        }
        sizeY = y + 1;
    }

    while (x > sizeX - 1) {
        cells.resize(sizeX + 1);
        std::vector<bool> subvector(sizeY, false);
        cells[sizeX] = std::move(subvector);
        ++sizeX;
    }
    x = Universe::torus(x, sizeX);
    y = Universe::torus(y, sizeY);
    cells[x][y] = value;
}

void Universe::changeCells(std::vector< std::vector<bool> >&& newcells) noexcept {
    cells = std::move(newcells);
}


bool Universe::getCell(int x, int y) const {
    x = Universe::torus(x, sizeX);
    y = Universe::torus(y, sizeY);
    return cells[x][y];
}


const std::vector<int>& Universe::getBornRule() const {
    return bornRule;
}

const std::vector<int>& Universe::getSurviveRule() const {
    return surviveRule;
}


int Universe::width() const {
    return sizeX;
}
int Universe::height() const {
    return sizeY;
}


int Universe::torus(int val, int size) const {
    if (val < 0)
        return size + val % size;
    if (val >= size)
        return val % size;
    return val;
}