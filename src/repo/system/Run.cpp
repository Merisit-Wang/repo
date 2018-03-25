#include "system/Run.h"
#include "debug/Log.h"
#include "system/Dir.h"

REPO_NS_BEGIN

namespace
{
    void runSystem(std::string cmd)
    {
        DBG_LOG("Run < " + cmd + " > ...");
        if (system(cmd.c_str()) == REPO_ERROR)
        {
            std::string msg = "Run cmd < " + cmd + " > error.";
            throw ErrorException(msg);
        }
    }
}

void Run::cmd(std::string cmd, std::string dir)
{
    std::string savedDir = Dir::getPwd();

    try
    {
        if (!dir.empty()) Dir::chDir(dir);
        runSystem(cmd);
        if (!dir.empty()) Dir::chDir(savedDir);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        throw ex;
    }
}

REPO_NS_END
