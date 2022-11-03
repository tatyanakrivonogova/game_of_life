#include "showerFactory.h"
#include "showUniverseFile.h"
#include "showUniverseConsole.h"

std::shared_ptr<showUniverse> showerFactory::buildShower(showerTypes type, Universe* u, std::ofstream* fout) {
    if (type == outputfile) {
        //return new showUniverseFile(u, fout);
        return std::make_shared<showUniverseFile>(u, fout);
    }
    if (type == console) {
        //return new showUniverseConsole(u);
        return std::make_shared<showUniverseConsole>(u);
    }
}