#pragma once
#include "createUniverse.h"
extern bool isDigit(char);

class createUniverseFile : public createUniverse {

private:
    std::ifstream& fin;
    std::string readLine();
    void getRules(std::string&, std::vector<int>&, std::vector<int>&);
    const std::string getName(std::string&);

public:

    createUniverseFile(std::ifstream&);
    ~createUniverseFile() = default;

    Universe create() override;
};


