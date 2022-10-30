#pragma once
#include "Universe.h"

class runLife {
private:
protected:
	bool checkRule(int, int);
	void changeUniverse();
	Universe& currentUniverse;

public:
	runLife(Universe&);
	virtual void run() = 0;
	virtual ~runLife() = default;
};
