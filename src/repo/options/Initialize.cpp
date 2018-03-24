#include "options/auto/AutoOption.h"
#include "runtime/RepoRuntime.h"
#include "runtime/Repo.h"

#include <string>

REPO_NS_BEGIN

DEFINE_OPTION(Initialize, "-i", "--init", "init repo")

private:
    OVERRIDE(int run(std::string gitCmd))
    {
        return Repo::init();
    }

END_DEFINE()

REPO_NS_END
