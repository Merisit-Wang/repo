#include "system/Dir.h"
#include "debug/Log.h"
#include "system/Run.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

REPO_NS_BEGIN

void Dir::assertDir(std::string dir)
{
    if (access(dir.c_str(), F_OK) == REPO_ERROR)
        throw ErrorException("Can't find dir : " + dir);
}

void Dir::mkDir(std::string dir)
{
    try
    {
        Run::cmd("mkdir -p " + dir);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        throw ErrorException("Can't create dir : " + dir);
    }
}

std::string Dir::getPwd()
{
    std::string currentDir(get_current_dir_name());
    currentDir += "/";
    DBG_LOG("Current dir : " + currentDir);

    return currentDir;
}

void Dir::chDir(std::string dir)
{
    assertDir(dir);
    DBG_LOG("Change dir to : " + dir);
    if (chdir(dir.c_str()) == REPO_ERROR)
        throw ErrorException("Can't find dir : " + dir);
}

void Dir::rmDir(std::string dir)
{
    try
    {
        Run::cmd("rm -rf " + dir);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        throw ErrorException("Can't delete dir : " + dir);
    }
}

REPO_NS_END
