#include "options/OptionFactory.h"
#include "options/Option.h"
#include "options/OptionMake.h"

REPO_NS_BEGIN

void OptionFactory::addOption(OptionMake& option)
{
    options.insert(&option);
}

std::set<OptionMake*> OptionFactory::getOptionList()
{
    return options;
}

REPO_NS_END
