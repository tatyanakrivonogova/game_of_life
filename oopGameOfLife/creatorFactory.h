#pragma once
#include "createUniverse.h"
#include <memory>

enum creatorTypes {
	file, generator
};

class creatorFactory
{
public:
	std::shared_ptr <createUniverse> buildCreator(creatorTypes type, std::ifstream* fin = nullptr);
};