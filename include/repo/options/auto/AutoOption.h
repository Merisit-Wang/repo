#ifndef INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF
#define INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF

#include "infra/base/repo.h"
#include "RepoRuntime.h"
#include "options/auto/AutoOptionFactory.h"

REPO_NS_BEGIN

template <typename OPTION>
struct AutoOption
{
    AutoOption()
    {
        REPO_RUNTIME(OptionFactory).addOption(opt);
    }

private:
    AutoOptionFactory<OPTION> opt;
};

#define LINE(type, line) type##line

#define DEFINE_OPTION(type) \
struct type; \
static AutoOption<type> LINE(type, __LINE__); \
struct type : Option

REPO_NS_END

#endif
