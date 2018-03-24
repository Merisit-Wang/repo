#ifndef INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF
#define INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF

#include "infra/base/repo.h"
#include "runtime/RepoRuntime.h"
#include "options/auto/AutoOptionFactory.h"
#include "options/core/OptionDescription.h"

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

#define DEFINE_OPTION(type, shortOpt, longOpt, description) \
struct type; \
static AutoOption<type> LINE(type, __LINE__); \
static OptionDescription type##_description(shortOpt, longOpt, description); \
struct type : CommonOption \
{ \
    type() : CommonOption(type##_description) {}; \

#define END_DEFINE() };

REPO_NS_END

#endif
