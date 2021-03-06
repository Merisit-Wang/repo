#include "ftesting/FtFixture.h"
#include "ft_env/FtCmdLine.h"
#include "runtime/RepoRuntime.h"

USING_REPO_NS

FTESTING_NS_BEGIN

FIXTURE(FtCmdLineParser)
{
    void given_cmd(std::string cmd)
    {
        REPO_RUNTIME(CmdLineParser).parse(createCmd(cmd.c_str()));
    }

    void assert_option_cmd(std::string option, std::string cmd)
    {
        ASSERT_THAT(REPO_RUNTIME(CmdLineParser).getOption(), is(option));
        ASSERT_THAT(REPO_RUNTIME(CmdLineParser).getGitCmd(), is(cmd));
    }

    TEST("repo")
    {
        given_cmd("repo");
        assert_option_cmd("--help", "");
    }

    TEST("--help")
    {
        given_cmd("repo --help");
        assert_option_cmd("--help", "");
    }

    TEST("pull")
    {
        given_cmd("repo pull");
        assert_option_cmd("", "pull");
    }

    TEST("branch -a")
    {
        given_cmd("repo branch -a");
        assert_option_cmd("", "branch -a");
    }

    TEST("-a branch -a")
    {
        given_cmd("repo -a branch -a");
        assert_option_cmd("-a", "branch -a");
    }

    TEST("--all branch -a")
    {
        given_cmd("repo --all branch -a");
        assert_option_cmd("--all", "branch -a");
    }
};

FTESTING_NS_END
