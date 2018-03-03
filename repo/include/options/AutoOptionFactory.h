#ifndef INCL_REPO_HD296639A_6C99_42BB_8A19_5872AC040140
#define INCL_REPO_HD296639A_6C99_42BB_8A19_5872AC040140

#include "infra/base/repo.h"
#include "infra/dci/role.h"

REPO_NS_BEGIN

struct Option;

DEFINE_ROLE(OptionMake)
{
    ABSTRACT(Option* make());
};

template < typename OPTION >
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
