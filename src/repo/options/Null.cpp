#include "options/auto/AutoOption.h"
#include "RepoRuntime.h"

#include <string>

REPO_NS_BEGIN

DEFINE_OPTION(Null)
{

private:
    OVERRIDE(int exec(std::string gitCmd))
    {
        if (gitCmd.empty()) return REPO_RUNTIME(CmdLineRunner).run();

        std::string cmd = "git " + gitCmd;
        return system(cmd.c_str());
    }

    OVERRIDE(bool match(std::string option) const)
    {
        if (option.empty()) return true;
        return false;
    }
};

REPO_NS_END
