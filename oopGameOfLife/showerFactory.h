#pragma once
#include "showUniverse.h"
#include <memory>

enum showerTypes {
	outputfile, console
};

class showerFactory
{
public:
	std::shared_ptr<showUniverse> buildShower(showerTypes type, Universe* u = nullptr, std::ofstream* fout = nullptr);
};