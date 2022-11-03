#pragma once
#include "showUniverse.h"
#include "Universe.h"

class showUniverseFile : public showUniverse {
private:
    std::ofstream* fout;

    const std::string createBornRule();
    const std::string createSurviveRule();
    const std::string createRulesString();

public:

    showUniverseFile(Universe*, std::ofstream*);
    ~showUniverseFile() = default;

    void show() override;
};

