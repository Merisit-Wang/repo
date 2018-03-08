#include "system/Dir.h"
#include "debug/Log.h"

#include <dirent.h>

REPO_NS_BEGIN

bool Dir::hasDir(std::string dir)
{
    DIR* d = opendir(dir.c_str());
    if (d != 0) return true;

    WARN_LOG("Cannot find dir : " + dir);
    return false;
}

REPO_NS_END
