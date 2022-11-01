#pragma once
#include "Universe.h"

class showUniverse {
protected:
	Universe* currentUniverse;

public:
	showUniverse(Universe* currentUniverse) : currentUniverse(currentUniverse) {}
	virtual void show() = 0;
	virtual ~showUniverse() = default;
};

