#include "ftesting/FtFixture.h"
#include "ft_env/FtCmdLine.h"
#include "ft_env/FtEnv.h"
#include "runtime/RepoRuntime.h"
#include "system/Dir.h"
#include "runtime/Repository.h"

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(FtOptionAll)
{
    SETUP()
    {
        FtEnv::init();
        REPO_RUN(createCmd("repo --init"));
    }

    TEARDOWN()
    {
        FtEnv::clean();
    }

    TEST("all git repo run git status success")
    {
        ASSERT_THAT(REPO_RUN(createCmd("repo --all status")), is(0));
    }

    TEST("run error")
    {
        Dir::rmDir(DIR_SPS);
        ASSERT_THAT(REPO_RUN(createCmd("repo --all status")), is(-1));
    }

    TEST("should switch work dir to repo root")
    {
        std::string repoRoot = Dir::getPwd();
        Dir::chDir(DIR_SPS);
        REPO_RUN(createCmd("repo --all status"));
        ASSERT_THAT(Dir::getPwd(), is(repoRoot));
    }
};

FTESTING_NS_END
