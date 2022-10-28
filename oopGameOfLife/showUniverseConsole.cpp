#include "showUniverseConsole.h"
#include "showUniverse.h"
#include <iostream>

showUniverseConsole::showUniverseConsole(Universe& currentUniverse) : showUniverse(currentUniverse) {}

void showUniverseConsole::show() {
	//system("cls");
	for (int i = 0; i < currentUniverse.height(); ++i) {
		for (int j = 0; j < currentUniverse.width(); ++j) {
			if (currentUniverse.getCell(i, j) == true) {
				std::cout << "* ";
			}
			else {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}