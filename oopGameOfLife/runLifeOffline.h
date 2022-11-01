#pragma once
#include <fstream>
#include "runLife.h"
#include "Universe.h"

extern void getAnswer(std::string& str);
extern bool checkFileFormat(std::string& str);
extern bool openFile(std::ifstream*, std::string&);
extern void checkExit(std::string&);

class runLifeOffline : public runLife
{
private:
    int numberOfIterations = 1;
    const std::string createBornRule();
    const std::string createSurviveRule();

public:

    runLifeOffline(Universe*);
    ~runLifeOffline() = default;

    void run() override;
};

