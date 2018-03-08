#include "runtime/RepoRuntime.h"
#include <iostream>

REPO_NS_BEGIN

namespace
{
    struct RepoRuntimeImpl : CmdLineRunner
                           , CmdLineParser
                           , OptionFactory
                           , RepoRuntime
    {

    private:
        IMPL_ROLE(CmdLineRunner);
        IMPL_ROLE(CmdLineParser);
        IMPL_ROLE(OptionFactory);
    };
}

RepoRuntime& RepoRuntime::getInstance()
{
    static RepoRuntimeImpl runtime;
    return runtime;
}

REPO_NS_END
