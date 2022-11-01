#include "runLifeOnline.h"
#include "runLife.h"
#include "Universe.h"
#include "createUniverseFile.h"
#include "runLife.h"
#include "createUniverse.h"
#include "showUniverse.h"
#include "showUniverseConsole.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <conio.h>

runLifeOnline::runLifeOnline(Universe* currentUniverse) : runLife(currentUniverse) {}

void runLifeOnline::run() {

    showUniverse* shower = new showUniverseConsole(currentUniverse);
    system("cls");
    std::cout << "Press any key for finishing game..." << std::endl;
    shower->show();

    Sleep(1000);

    while (1) {
        changeUniverse();
        system("cls");
        std::cout << "Press any key for finishing game..." << std::endl;
        shower->show();
        Sleep(1000);
        if (_kbhit()) {
            std::cout << "Game over!" << std::endl;
            return;
        }
    }
}

