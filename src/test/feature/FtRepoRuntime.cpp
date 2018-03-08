#include "ftesting/FtFixture.h"
#include "feature/FtCmdLine.h"
#include "runtime/RepoRuntime.h"

#include <stdio.h>

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(FtRepoRuntime)
{

    TEST("run repo status")
    {
        CmdLine cmdLine = CmdLineFactory().createWith("repo -h");
        REPO_RUNTIME(CmdLineParser).parse(cmdLine);
        printf("status = %d\n",REPO_RUNTIME(CmdLineRunner).run());
    }
};

FTESTING_NS_END
