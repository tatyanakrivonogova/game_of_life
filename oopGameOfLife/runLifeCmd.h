#pragma once
#include <fstream>
#include "runLife.h"
#include "Universe.h"

extern void getAnswer(std::string& str);
extern bool checkFileFormat(std::string& str);
extern bool openFile(std::ifstream*, std::string&);
extern void checkExit(std::string&);

class runLifeCmd : public runLife
{
private:
    std::ofstream* fout;
    int numberOfIterations = 1;

    const std::string createBornRule();
    const std::string createSurviveRule();
    const std::string createRulesString();

public:

    runLifeCmd(Universe*, std::ofstream*, int);
    ~runLifeCmd() = default;

    void run() override;
};

