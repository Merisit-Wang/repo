#include "runtime/Repository.h"
#include "debug/Log.h"
#include "system/Dir.h"
#include "system/Run.h"
#include "system/File.h"

REPO_NS_BEGIN

namespace
{
    static std::string configFileName = "config";
}

int Repository::init()
{
    if (!initVerify())
    {
        ERR_LOG("Initialize repository error.");
        return REPO_ERROR;
    }

    if (Dir::mkDir(REPO) != REPO_SUCCESS) return REPO_ERROR;

    std::string savedDir = Dir::getPwd();
    Dir::chDir(REPO);
    try
    {
        File::createFile(configFileName);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        return REPO_ERROR;
    }
    Dir::chDir(savedDir);

    INFO_LOG("Initialize repository done.");
    return REPO_SUCCESS;
}

int Repository::createConfig()
{

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

    if (!runDir.empty())
    {
        if (Dir::chDir(runDir) != REPO_SUCCESS)
            return REPO_ERROR;
    }

    DBG_LOG("Run < " + gitCmd + " > ...");
    int result = Run::cmd(gitCmd);
    Dir::chDir(savedDir);

    if (result != REPO_SUCCESS) return ERR_LOG("Run < " + gitCmd + " > error.");

    INFO_LOG("Run < " + gitCmd + " > done.");
    return result;
}

REPO_NS_END
