#include "runtime/Repository.h"
#include "debug/Log.h"
#include "system/Dir.h"

#include <string>

REPO_NS_BEGIN

namespace
{
    static const std::string DIR_CPU = "Code_CPUPlatform/";
    static const std::string DIR_PUB = "Code_LTE/pub/";
    static const std::string DIR_SDR = "Code_LTE/sdr/";
    static const std::string DIR_SPS = "Code_LTE/sps/";
    static const std::string DIR_PROJECT = "Project/";
    static const std::string DIR_BUILD = "DailyBuild/";
}

void Repository::init()
{
    if (!isValidRepo())
    {
        ERR_LOG("Initialize repository error.");
        return;
    }



}

bool Repository::isValidRepo() const
{
    return Dir::hasDir(DIR_CPU)
        && Dir::hasDir(DIR_PUB)
        && Dir::hasDir(DIR_SDR)
        && Dir::hasDir(DIR_SPS);
}

REPO_NS_END
