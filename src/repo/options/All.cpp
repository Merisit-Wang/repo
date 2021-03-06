#include "options/auto/AutoOption.h"
#include "runtime/RepoRuntime.h"
#include "runtime/Repository.h"
#include "debug/Log.h"

#include <string>

REPO_NS_BEGIN

DEFINE_OPTION(All, "-a", "--all", "run git cmd in each git repo")

private:
    OVERRIDE(int run(std::string gitCmd))
    {
        if (gitCmd.empty()) return ERR_LOG("Can't have git cmd!");
        if (Repository::runWithAllDir(gitCmd) != REPO_SUCCESS)
            return ERR_LOG("Runtime error, please check.");

        return INFO_LOG("All git repo run < git " + gitCmd + " > done.");
    }

END_DEFINE()

REPO_NS_END
