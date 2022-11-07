#include "creatorFactory.h"
#include "createUniverseFile.h"
#include "createUniverseGenerator.h"
#include <memory>

std::shared_ptr <createUniverse> creatorFactory::buildCreator(creatorTypes type, std::ifstream* fin) {
    if (type == file) {
        return std::make_shared<createUniverseFile>(fin);
    } else 
    if (type == generator) {
        return std::make_shared<createUniverseGenerator>();
    } else {
        return nullptr;
    }
}