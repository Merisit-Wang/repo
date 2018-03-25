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

int Repository::changeWorkDirToRepoRoot()
{
    while(!Dir::isRootDir())
    {
        if (Dir::hasDir(Dir::getPwd() + DIR_REPO)) break;
        Dir::chDir(Dir::getPwd() + "..");
    }

    if (Dir::isRootDir() || !isValid())
        return ERR_LOG("Not a repository (or any of the parent directories) : .repo");
    return REPO_SUCCESS;
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

int Repository::runWithAllDir(std::string gitCmd, bool hasExtendDir)
{
    if (changeWorkDirToRepoRoot() == REPO_ERROR) return REPO_ERROR;
    int result;
    result = runGitCmd(gitCmd, DIR_CPU);
    result = runGitCmd(gitCmd, DIR_PUB);
    result = runGitCmd(gitCmd, DIR_SDR);
    result = runGitCmd(gitCmd, DIR_SPS);

    if (hasExtendDir)
    {
        result = runGitCmd(gitCmd, DIR_PROJECT);
        result = runGitCmd(gitCmd, DIR_BUILD);
    }

    return result;
}

REPO_NS_END
