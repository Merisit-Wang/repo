#include "runtime/Repository.h"
#include "debug/Log.h"
#include "system/Dir.h"
#include "system/Run.h"
#include "system/File.h"

REPO_NS_BEGIN

namespace
{
    static std::string configFileName = "config";
    static std::string configPath = DIR_REPO + configFileName;
    static std::string repoRoot = "root=" + Dir::getPwd();
    static std::string debugSwitch = "debug=0";
}

int Repository::init()
{
    try
    {
        initVerify();
        Dir::mkDir(DIR_REPO);
        createConfig();
    }
    catch(ErrorException& ex)
    {
        ex.what();
        return ERR_LOG("Initialize repository error.");;
    }
    return INFO_LOG("Initialize repository done.");
}

void Repository::createConfig()
{
    File::create(configFileName, DIR_REPO);
    File::writeLen(configPath, repoRoot);
    File::writeLen(configPath, debugSwitch);
}

bool Repository::isValid()
{
    std::string repoRoot;
    try
    {
        Dir::assertDir(DIR_REPO);
        repoRoot = File::readLen(configPath);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        return false;
    }

    if (repoRoot.erase(0, 5) != Dir::getPwd()) return false;

    return true;
}

void Repository::rmRepo()
{
    Dir::rmDir(DIR_REPO);
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
