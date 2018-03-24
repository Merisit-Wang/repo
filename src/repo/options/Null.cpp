#include "options/auto/AutoOption.h"
#include "runtime/RepoRuntime.h"
#include "debug/Log.h"

#include <string>

REPO_NS_BEGIN

DEFINE_OPTION(Null, "", "", "")

private:
    OVERRIDE(int run(std::string gitCmd))
    {
        if (gitCmd.empty()) return REPO_SUCCESS;

        std::string cmd = "git " + gitCmd;
        int result = system(cmd.c_str());

        if (result == REPO_SUCCESS)
        {
            INFO_LOG("Run < " + cmd + " > done.");
        }
        else
        {
            ERR_LOG("Run < " + cmd + " > error.");
        }

        return result;
    }

END_DEFINE()

REPO_NS_END
