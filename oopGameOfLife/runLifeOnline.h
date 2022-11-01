#pragma once
#include "Universe.h"
#include "runLife.h"
class runLifeOnline : public runLife {

public:

    runLifeOnline(Universe*);
    ~runLifeOnline() = default;

    void run() override;
};

