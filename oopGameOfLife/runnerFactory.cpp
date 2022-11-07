#include "runnerFactory.h"
#include "runLifeOnline.h"
#include "runLifeOffline.h"
#include "runLifeCmd.h"

std::shared_ptr<runLife> runnerFactory::buildRunner(runnerTypes type, Universe* u, std::ofstream* fout, int n) {
    if (type == cmd) {
        return std::make_shared<runLifeCmd>(u, fout, n);
    } else
    if (type == online) {
        return std::make_shared<runLifeOnline>(u);
    } else
    if (type == offline) {
        return std::make_shared<runLifeOffline>(u);
    } else {
        return nullptr;
    }
}
