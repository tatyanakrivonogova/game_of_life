#include "showerFactory.h"
#include "showUniverseFile.h"
#include "showUniverseConsole.h"

std::shared_ptr<showUniverse> showerFactory::buildShower(showerTypes type, Universe* u, std::ofstream* fout) {
    if (type == outputfile) {
        return std::make_shared<showUniverseFile>(u, fout);
    } else
    if (type == console) {
        return std::make_shared<showUniverseConsole>(u);
    } else {
        return nullptr;
    }
}