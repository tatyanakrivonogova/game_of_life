#include "creatorFactory.h"
#include "createUniverseFile.h"
#include "createUniverseGenerator.h"
#include <memory>

std::shared_ptr <createUniverse> creatorFactory::buildCreator(creatorTypes type, std::ifstream* fin) {
    if (type == file) {
        //return new createUniverseFile(fin);
        return std::make_shared<createUniverseFile>(fin);
    }
    if (type == generator) {
        //return new createUniverseGenerator();
        return std::make_shared<createUniverseGenerator>();
    }
}