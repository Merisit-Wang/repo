#include "ftesting/FtFixture.h"
#include "feature/FtCmdLine.h"
#include "runtime/RepoRuntime.h"
#include "../../../../include/repo/system/Dir.h"

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(FtOptionInitalize)
{
    TEST("should create .repo dir")
    {
        CmdLine cmdLine = CmdLineFactory().createWith("repo --init");
        REPO_RUNTIME(CmdLineParser).parse(cmdLine);
        REPO_RUNTIME(CmdLineRunner).run();
        ASSERT_THAT(Dir::hasDir(".repo"), is(true));
        Dir::rmDir(".repo");
    }
};

FTESTING_NS_END
