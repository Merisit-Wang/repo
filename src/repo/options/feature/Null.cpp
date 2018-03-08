#include "options/auto/AutoOption.h"
#include "runtime/RepoRuntime.h"

#include <string>

REPO_NS_BEGIN

DEFINE_OPTION(Null, "", "", "")

private:
    OVERRIDE(int run(std::string gitCmd))
    {
        if (gitCmd.empty()) return REPO_RUNTIME(CmdLineRunner).run();

        std::string cmd = "git " + gitCmd;
        return system(cmd.c_str());
    }

END_DEFINE()

REPO_NS_END
