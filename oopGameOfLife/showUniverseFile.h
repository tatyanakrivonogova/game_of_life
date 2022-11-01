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

    showUniverseFile(std::ofstream*, Universe*);
    ~showUniverseFile() = default;

    void show() override;
};

