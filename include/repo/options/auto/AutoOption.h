#ifndef INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF
#define INCL_REPO_H49606200_9639_4AC2_BEFF_2594ACCBBCEF

#include "infra/base/repo.h"
#include "RepoRuntime.h"
#include "options/auto/AutoOptionFactory.h"

#include <stdio.h>

REPO_NS_BEGIN

template <typename OPTION>
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

REPO_NS_END

#endif
