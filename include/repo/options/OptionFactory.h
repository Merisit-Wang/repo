#ifndef INCL_REPO_H3FB601EF_3EF1_47D8_9DA7_76475544770C
#define INCL_REPO_H3FB601EF_3EF1_47D8_9DA7_76475544770C

#include "infra/base/repo.h"
#include "infra/dci/role.h"

#include <set>

REPO_NS_BEGIN

struct OptionMake;

DEFINE_ROLE(OptionFactory)
{
    void addOption(OptionMake&);
    std::set<OptionMake*> getOptionList();

private:
    std::set<OptionMake*> options;
};

REPO_NS_END

#endif
