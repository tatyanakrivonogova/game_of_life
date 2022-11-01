#pragma once
#include "createUniverse.h"

//enum creatorTypes {
//	//createUniverseFile, createUniverseGenerator
//	file, generator
//};

class creatorFactory
{
public:
	createUniverse* buildCreator();
	createUniverse* buildCreator(std::ifstream& fin);
};