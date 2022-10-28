#pragma once
#include "showUniverse.h"
#include "Universe.h"

class showUniverseFile : public showUniverse {
private:
    std::ofstream& fout;

public:

    showUniverseFile(std::ofstream&, Universe&);
    ~showUniverseFile() = default;

    void show() override;
};

