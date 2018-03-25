#include "system/Dir.h"
#include "debug/Log.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

REPO_NS_BEGIN

bool Dir::hasDir(std::string dir)
{
    if (access(dir.c_str(), F_OK) == REPO_SUCCESS) return true;

    ERR_LOG("Cannot find dir : " + dir);
    return false;
}

int Dir::mkDir(std::string dir)
{
    std::string cmd = "mkdir -p " + dir;
    if (system(cmd.c_str()) == REPO_SUCCESS)
        return REPO_SUCCESS;

    ERR_LOG("Cannot create dir : " + dir);
    return REPO_ERROR;
}

std::string Dir::getPwd()
{
    std::string currentDir(get_current_dir_name());
    currentDir += "/";
    DBG_LOG("Current dir : " + currentDir);

    return currentDir;
}

int Dir::chDir(std::string dir)
{
    if (!hasDir(dir)) return REPO_ERROR;
    DBG_LOG("Change dir to : " + dir);
    if (chdir(dir.c_str()) == REPO_SUCCESS) return REPO_SUCCESS;
    return REPO_ERROR;
}

int Dir::rmDir(std::string dir)
{
    std::string cmd = "rm -rf " + dir;
    if (system(cmd.c_str()) == REPO_SUCCESS) return REPO_SUCCESS;

    ERR_LOG("Cannot delete dir : " + dir);
    return REPO_ERROR;
}

REPO_NS_END
