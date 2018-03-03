#ifndef INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF
#define INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF

#include "infra/base/repo.h"
#include "RepoRuntime.h"
#include "options/Option.h"
#include <stdio.h>
#include "options/AutoOptionFactory.h"

REPO_NS_BEGIN

template < typename OPTION >
struct AutoOption
{
    AutoOption()
    {
        printf("=====>auto option create\n");
        REPO_RUNTIME(OptionFactory).addOption(opt);
    }

private:
    AutoOptionFactory<OPTION> opt;
};

#define DEFINE_OPTION(type) \
struct type;\
static REPO_NS::AutoOption<type> type__LINE__;\
struct type : Option

REPO_NS_END

#endif
