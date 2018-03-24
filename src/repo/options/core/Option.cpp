#include "options/core/Option.h"
#include "options/core/OptionDescription.h"
#include "runtime/RepoRuntime.h"

REPO_NS_BEGIN

CommonOption::CommonOption(OptionDescription& desc)
    : desc(desc)
{
    REPO_RUNTIME(OptionFactory).addDescription(desc);
}

int CommonOption::exec(std::string gitCmd)
{
    return run(gitCmd);
}

bool CommonOption::match(std::string option) const
{
    return desc.thisOption(option);
}

REPO_NS_END
