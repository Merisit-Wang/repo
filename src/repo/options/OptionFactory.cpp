#include "options/OptionFactory.h"
#include "options/Option.h"
#include "options/OptionMake.h"

REPO_NS_BEGIN

void OptionFactory::addOption(OptionMake& option)
{
    options.insert(&option);
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

REPO_NS_END
