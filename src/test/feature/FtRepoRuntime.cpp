#include "ftesting/FtFixture.h"
#include "ft_env/FtCmdLine.h"
#include "runtime/RepoRuntime.h"

#include <stdio.h>

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(FtRepoRuntime)
{
    TEST("unkown option")
    {
        ASSERT_THAT(REPO_RUN(createCmd("repo --xxx")), is(0));
        ASSERT_THAT(REPO_RUNTIME(CmdLineParser).getOption(), is(std::string("--help")));
    }
};

FTESTING_NS_END
