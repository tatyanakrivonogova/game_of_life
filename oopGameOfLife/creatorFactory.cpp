#include "creatorFactory.h"
#include "createUniverseFile.h"
#include "createUniverseGenerator.h"

createUniverse* creatorFactory::buildCreator() {
    return new createUniverseGenerator();
}

createUniverse* creatorFactory::buildCreator(std::ifstream& fin) {
    return new createUniverseFile(fin);
}