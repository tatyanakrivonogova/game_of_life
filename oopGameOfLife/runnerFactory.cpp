#include "runnerFactory.h"
#include "runLifeOnline.h"
#include "runLifeOffline.h"
#include "runLifeCmd.h"

std::shared_ptr<runLife> runnerFactory::buildRunner(runnerTypes type, Universe* u, std::ofstream* fout, int n) {
    if (type == cmd) {
        //return new runLifeCmd(u, fout, n);
        return std::make_shared<runLifeCmd>(u, fout, n);
    }
    if (type == online) {
        //return new runLifeOnline(u);
        return std::make_shared<runLifeOnline>(u);
    }
    if (type == offline) {
        //return new runLifeOffline(u);
        return std::make_shared<runLifeOffline>(u);
    }
}
