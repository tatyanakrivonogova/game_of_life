#pragma once
#include "createUniverse.h"

class createUniverseGenerator : public createUniverse
{
private:

public:

    ~createUniverseGenerator() = default;

    Universe create() override;
};
