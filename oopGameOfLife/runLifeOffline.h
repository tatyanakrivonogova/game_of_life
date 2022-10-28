#pragma once
#include <fstream>
#include "runLife.h"
#include "Universe.h"

extern void getAnswer(std::string& str);
extern bool checkFileFormat(std::string& str);
extern bool openFile(std::ifstream&, std::string&);
extern void checkExit(std::string&);

class runLifeOffline : public runLife
{
private:
    //std::ofstream& fout;
    int number_of_iterations = 1;

    const std::string createBornRule();
    const std::string createSurviveRule();
    const std::string createRulesString();

public:

    runLifeOffline(Universe&);
    ~runLifeOffline() = default;

    void run() override;
};
