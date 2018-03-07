#include "options/OptionFactory.h"
#include "options/Option.h"
#include "options/OptionMake.h"
#include "options/OptionDescription.h"

REPO_NS_BEGIN

void OptionFactory::addOption(OptionMake& option)
{
    options.insert(&option);
}

void OptionFactory::addDescription(OptionDescription& description)
{
    if (description.isNull()) return ;
    desc.insert(&description);
}

Option* OptionFactory::makeOption(std::string expect)
{
    for (auto opt : options)
    {
        Option* option = opt->make();
        if (option->match(expect)) return option;
    }
    return 0;
}

std::set<OptionDescription*> OptionFactory::getDescripions()
{
    return desc;
}

REPO_NS_END
