#ifndef INCL_REPO_H17B967DB_FCF6_45F4_96E3_2DA03E7C7405
#define INCL_REPO_H17B967DB_FCF6_45F4_96E3_2DA03E7C7405

#include "infra/base/repo.h"
#include "options/core/OptionMake.h"

REPO_NS_BEGIN

template <typename OPTION>
struct AutoOptionFactory : OptionMake
{

private:
    OVERRIDE(Option* make())
    {
        static OPTION opt;
        return &opt;
    }
};

REPO_NS_END

#endif
