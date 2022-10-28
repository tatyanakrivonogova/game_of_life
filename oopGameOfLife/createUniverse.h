#pragma once
#include "Universe.h"

class createUniverse {

public:
	virtual Universe create() = 0;
	virtual ~createUniverse() = default;
};
