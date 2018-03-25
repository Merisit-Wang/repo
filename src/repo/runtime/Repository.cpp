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
    try
    {
        initVerify();
        Dir::mkDir(REPO);
        File::createFile(configFileName, REPO);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        return ERR_LOG("Initialize repository error.");;
    }
    return INFO_LOG("Initialize repository done.");
}

int Repository::createConfig()
{

    return REPO_SUCCESS;
}

bool Repository::isValid()
{
    try
    {
        Dir::assertDir(REPO);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        return false;
    }

    return true;
}

void Repository::rmRepo()
{
    Dir::rmDir(REPO);
}

void Repository::initVerify()
{
    Dir::assertDir(DIR_CPU);
    Dir::assertDir(DIR_PUB);
    Dir::assertDir(DIR_SDR);
    Dir::assertDir(DIR_SPS);
}

int Repository::runGitCmd(std::string cmd, std::string runDir)
{
    std::string gitCmd = "git " + cmd;
    try
    {
        Run::cmd(gitCmd, runDir);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        return ERR_LOG("Run < " + gitCmd + " > error.");
    }

    return INFO_LOG("Run < " + gitCmd + " > done.");
}

REPO_NS_END
