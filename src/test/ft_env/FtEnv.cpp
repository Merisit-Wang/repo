#include "ft_env/FtEnv.h"
#include "runtime/Repository.h"
#include "system/Dir.h"

USING_REPO_NS

FTESTING_NS_BEGIN

void FtEnv::init()
{
    Dir::mkDir(DIR_CPU);
    Dir::mkDir(DIR_LTE);
    Dir::mkDir(DIR_PUB);
    Dir::mkDir(DIR_SDR);
    Dir::mkDir(DIR_SPS);
    Dir::mkDir(DIR_PROJECT);
    Dir::mkDir(DIR_BUILD);
}

void FtEnv::clean()
{
    Dir::rmDir(DIR_CPU);
    Dir::rmDir(DIR_PUB);
    Dir::rmDir(DIR_SDR);
    Dir::rmDir(DIR_SPS);
    Dir::rmDir(DIR_PROJECT);
    Dir::rmDir(DIR_BUILD);
    Dir::rmDir(DIR_LTE);
}

FTESTING_NS_END
