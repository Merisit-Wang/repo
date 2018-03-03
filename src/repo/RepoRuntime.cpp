#include "RepoRuntime.h"
#include <iostream>

REPO_NS_BEGIN

namespace
{
    struct RepoRuntimeImpl : OptionFactory
                           , RepoRuntime
    {

    private:
        IMPL_ROLE(OptionFactory);
    };
}

RepoRuntime& RepoRuntime::getInstance()
{
    static RepoRuntimeImpl runtime;
    return runtime;
}

REPO_NS_END
