#pragma once
#include "Universe.h"
#include "showUniverse.h"

class showUniverseConsole : public showUniverse {

private:

public:

    showUniverseConsole(Universe*);
    ~showUniverseConsole() = default;

    void show() override;
};

