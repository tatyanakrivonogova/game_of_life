#pragma once
#include "createUniverse.h"

class createUniverseFile : public createUniverse {

private:
    std::ifstream& fin;
    std::string readLine();
    void readRules(const std::string&, std::vector<int>&, std::vector<int>&);

public:

    createUniverseFile(std::ifstream&);
    ~createUniverseFile() = default;

    Universe create() override;
};


