#pragma once
#include "runLife.h"
#include "runnerFactory.h"

//enum runnerTypes {
//	//createUniverseFile, createUniverseGenerator
//	online, offline, cmd
//};

class runnerFactory
{
public:
	runLife* buildRunner(Universe&, std::ofstream&, int);
	runLife* buildRunner(Universe&);
};