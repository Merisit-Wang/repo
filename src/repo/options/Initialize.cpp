#include "options/auto/AutoOption.h"
#include "runtime/RepoRuntime.h"
#include "system/Dir.h"
#include "debug/Log.h"

#include <string>

REPO_NS_BEGIN

DEFINE_OPTION(Initialize, "-i", "--init", "init repo")

private:
    OVERRIDE(int run(std::string gitCmd))
    {
        if (Dir::mkDir(".repo") != REPO_SUCCESS) return REPO_ERROR;

        INFO_LOG("repo initalized!");
        return REPO_SUCCESS;
    }

END_DEFINE()

REPO_NS_END
