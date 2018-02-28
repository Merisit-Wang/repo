#include "ftesting/FtFixture.h"
#include "RepoRuntime.h"

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(RepoRuntimeTest)
{
    TEST("run git --help")
    {
        REPO_RUNTIME("git --help");
    }
};

FTESTING_NS_END
