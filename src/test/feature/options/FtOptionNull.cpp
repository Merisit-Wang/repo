#include "ftesting/FtFixture.h"
#include "ft_env/FtCmdLine.h"
#include "ft_env/FtEnv.h"
#include "runtime/RepoRuntime.h"

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(FtOptionNull)
{
    TEST("should run git status success")
    {
        ASSERT_THAT(REPO_RUN(createCmd("repo status")), is(0));
    }
};

FTESTING_NS_END
