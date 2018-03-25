#include "system/Run.h"

REPO_NS_BEGIN

int Run::cmd(std::string cmd)
{
    return system(cmd.c_str());
}

REPO_NS_END
