#include "creatorFactory.h"
#include "createUniverseFile.h"
#include "createUniverseGenerator.h"

createUniverse* creatorFactory::buildCreator(creatorTypes type, std::ifstream* fin = nullptr) {
    if (type == file) {
        return new createUniverseFile(fin);
    }
    if (type == generator) {
        return new createUniverseGenerator();
    }
}