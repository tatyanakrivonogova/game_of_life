#include "showUniverseFile.h"
#include "showUniverse.h"
#include <iostream>
#include <fstream>

showUniverseFile::showUniverseFile(std::ofstream& fout, Universe& currentUniverse) : fout(fout), showUniverse(currentUniverse) {}

void showUniverseFile::show() {
	for (int i = 0; i < currentUniverse.height(); ++i) {
		for (int j = 0; j < currentUniverse.width(); ++j) {
			if (currentUniverse.getCell(i, j) == true) {
				fout << "* ";
			}
			else {
				fout << "  ";
			}
		}
		fout << std::endl;
	}
}