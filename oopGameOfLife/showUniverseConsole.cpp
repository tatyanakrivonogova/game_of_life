#include "showUniverseConsole.h"
#include "showUniverse.h"
#include <iostream>

showUniverseConsole::showUniverseConsole(Universe* currentUniverse) : showUniverse(currentUniverse) {}

void showUniverseConsole::show() {
	for (int i = 0; i <= currentUniverse->width(); ++i) {
		std::cout << "_";
	}
	std::cout << std::endl;

	for (int i = 0; i < currentUniverse->height(); ++i) {
		std::cout << "|";
		for (int j = 0; j < currentUniverse->width(); ++j) {
			if (currentUniverse->getCell(j, i) == true) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "|";
		std::cout << std::endl;
	}

	for (int i = 0; i <= currentUniverse->width(); ++i) {
		std::cout << "_";
	}
	std::cout << std::endl;
}