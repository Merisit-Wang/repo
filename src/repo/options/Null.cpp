#include "options/auto/AutoOption.h"
#include "runtime/RepoRuntime.h"
#include "debug/Log.h"
#include "runtime/Repository.h"

#include <string>

REPO_NS_BEGIN

DEFINE_OPTION(Null, "", "", "")

private:
    OVERRIDE(int run(std::string gitCmd))
    {
        if (gitCmd.empty()) return REPO_SUCCESS;

        return Repository::runGitCmd(gitCmd);
    }

END_DEFINE()

REPO_NS_END
