#ifndef INCL_REPO_H3FB601EF_3EF1_47D8_9DA7_76475544770C
#define INCL_REPO_H3FB601EF_3EF1_47D8_9DA7_76475544770C

#include "infra/base/repo.h"
#include "infra/dci/role.h"

#include <set>
#include <string>

REPO_NS_BEGIN

struct OptionMake;
struct Option;
struct OptionDescription;

DEFINE_ROLE(OptionFactory)
{
    void addOption(OptionMake&);
    void addDescription(OptionDescription&);

    Option* makeOption(std::string);
    std::set<OptionDescription*> getDescripions();

private:
    std::set<OptionMake*> options;
    std::set<OptionDescription*> desc;
};

REPO_NS_END

#endif
