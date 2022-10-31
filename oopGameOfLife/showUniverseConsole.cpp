#include "showUniverseConsole.h"
#include "showUniverse.h"
#include <iostream>

showUniverseConsole::showUniverseConsole(Universe& currentUniverse) : showUniverse(currentUniverse) {}

void showUniverseConsole::show() {
	for (int i = 0; i < currentUniverse.height(); ++i) {
		for (int j = 0; j < currentUniverse.width(); ++j) {
			if (currentUniverse.getCell(j, i) == true) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}