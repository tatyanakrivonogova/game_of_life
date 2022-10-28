#pragma once
#include "Universe.h"
#include "runLife.h"
class runLifeOnline : public runLife {
    //private:
    //    Universe& currentUniverse;
    //    int checkRule(int, int);

public:

    runLifeOnline(Universe&);
    ~runLifeOnline() = default;

    void run() override;
};

