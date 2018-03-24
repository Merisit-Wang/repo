#ifndef INCL_REPO_H1F684F59_87C5_405C_8A23_CE0146B0242D
#define INCL_REPO_H1F684F59_87C5_405C_8A23_CE0146B0242D

#include "infra/base/repo.h"
#include "infra/dci/role.h"
#include "options/core/Option.h"

REPO_NS_BEGIN

DEFINE_ROLE(OptionMake)
{
    ABSTRACT(Option* make());
};

REPO_NS_END

#endif
