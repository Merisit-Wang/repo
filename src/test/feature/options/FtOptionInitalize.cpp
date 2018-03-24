#include "ftesting/FtFixture.h"
#include "ft_env/FtCmdLine.h"
#include "ft_env/FtEnv.h"
#include "runtime/RepoRuntime.h"
#include "system/Dir.h"
#include "runtime/Repo.h"

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(FtOptionInitalize)
{
    SETUP()
    {
        FtEnv::init();
    }

    TEARDOWN()
    {
        FtEnv::clean();
    }

    TEST("should init repo success")
    {
        REPO_RUN(createCmd("repo --init"));
        ASSERT_THAT(Repo::isValid(), is(true));
        Repo::rmRepo();
    }
};

FTESTING_NS_END
