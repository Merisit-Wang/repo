#include "RepoRuntime.h"
#include <iostream>

REPO_NS_BEGIN

namespace
{
    struct RepoRuntimeImpl : RepoRuntime
    {

    private:
        OVERRIDE(void run(std::string cmd))
        {
            std::cout << cmd << std::endl;
        }
    };
}

RepoRuntime& RepoRuntime::getInstance()
{
    static RepoRuntimeImpl runtime;
    return runtime;
}

REPO_NS_END
