#include "runtime/Repository.h"
#include "debug/Log.h"
#include "system/Dir.h"

REPO_NS_BEGIN

int Repository::init()
{
    if (!initVerify())
    {
        ERR_LOG("Initialize repository error.");
        return REPO_ERROR;
    }

    if (Dir::mkDir(REPO) != REPO_SUCCESS) return REPO_ERROR;

    INFO_LOG("Initialize repository done.");
    return REPO_SUCCESS;
}

bool Repository::isValid()
{
    return Dir::hasDir(REPO);
}

void Repository::rmRepo()
{
    Dir::rmDir(REPO);
}

bool Repository::initVerify()
{
    return Dir::hasDir(DIR_CPU)
        && Dir::hasDir(DIR_PUB)
        && Dir::hasDir(DIR_SDR)
        && Dir::hasDir(DIR_SPS);
}

int Repository::runGitCmd(std::string cmd, std::string runDir)
{
    std::string gitCmd = "git " + cmd;
    std::string savedDir = Dir::getPwd();

    if (!runDir.empty()) Dir::chDir(runDir);
    DBG_LOG("Run < " + gitCmd + " > ...");
    int result = system(gitCmd.c_str());
    Dir::chDir(savedDir);

    if (result != REPO_SUCCESS) ERR_LOG("Run < " + gitCmd + " > error.");

    INFO_LOG("Run < " + gitCmd + " > done.");
    return result;
}

REPO_NS_END
