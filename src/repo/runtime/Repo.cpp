#include "runtime/Repo.h"
#include "debug/Log.h"
#include "system/Dir.h"

REPO_NS_BEGIN

int Repo::init()
{
    if (!verify())
    {
        ERR_LOG("Initialize repository error.");
        return REPO_ERROR;
    }

    if (Dir::mkDir(REPO) != REPO_SUCCESS) return REPO_ERROR;

    INFO_LOG("Initialize repository done.");
    return REPO_SUCCESS;
}

bool Repo::isValid()
{
    return Dir::hasDir(REPO);
}

void Repo::rmRepo()
{
    Dir::rmDir(REPO);
}

bool Repo::verify()
{
    return Dir::hasDir(DIR_CPU)
        && Dir::hasDir(DIR_PUB)
        && Dir::hasDir(DIR_SDR)
        && Dir::hasDir(DIR_SPS);
}

REPO_NS_END
