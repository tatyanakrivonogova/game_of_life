#pragma once
#include "Universe.h"

class runLife {
private:
protected:
	int checkRule(int, int);
	Universe& currentUniverse;

public:
	runLife(Universe&);
	virtual void run() = 0;
	virtual ~runLife() = default;
};
