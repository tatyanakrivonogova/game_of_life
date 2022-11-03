#pragma once
#include "runLife.h"
#include "runnerFactory.h"
#include <memory>

enum runnerTypes {
	online, offline, cmd
};

class runnerFactory
{
public:
	std::shared_ptr<runLife> buildRunner(runnerTypes type, Universe* u = nullptr, std::ofstream* fout = nullptr, int n = 1);
};