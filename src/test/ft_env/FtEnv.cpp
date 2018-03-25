#include "ft_env/FtEnv.h"
#include "runtime/Repository.h"
#include "system/Dir.h"

USING_REPO_NS

FTESTING_NS_BEGIN

void FtEnv::init()
{
    Dir::mkDir(DIR_CPU);
    Dir::mkDir(DIR_PUB);
    Dir::mkDir(DIR_SDR);
    Dir::mkDir(DIR_SPS);
    Dir::mkDir(DIR_PROJECT);
    Dir::mkDir(DIR_BUILD);
    Repository::runGitCmd("init", DIR_CPU);
    Repository::runGitCmd("init", DIR_PUB);
    Repository::runGitCmd("init", DIR_SDR);
    Repository::runGitCmd("init", DIR_SPS);
    Repository::runGitCmd("init", DIR_PROJECT);
    Repository::runGitCmd("init", DIR_BUILD);
}

void FtEnv::clean()
{
    Dir::rmDir(DIR_CPU);
    Dir::rmDir(DIR_PUB);
    Dir::rmDir(DIR_SDR);
    Dir::rmDir(DIR_SPS);
    Dir::rmDir(DIR_PROJECT);
    Dir::rmDir(DIR_BUILD);
}

FTESTING_NS_END
