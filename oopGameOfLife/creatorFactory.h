#pragma once
#include "createUniverse.h"

enum creatorTypes {
	file, generator
};

class creatorFactory
{
public:
	createUniverse* buildCreator(creatorTypes, std::ifstream*);
};