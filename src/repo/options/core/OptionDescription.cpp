#include "options/core/OptionDescription.h"

REPO_NS_BEGIN

OptionDescription::OptionDescription()
    : shortOpt("")
    , longOpt("")
    , description("")
{
}

OptionDescription::OptionDescription(std::string shortOpt
    , std::string longOpt
    , std::string description)
    : shortOpt(shortOpt)
    , longOpt(longOpt)
    , description(description)
{
}

bool OptionDescription::thisOption(std::string option) const
{
    if (option == shortOpt || option == longOpt) return true;
    return false;
}

bool OptionDescription::isNull() const
{
    return shortOpt.empty() && longOpt.empty();
}

std::string OptionDescription::getShortOpt() const
{
    return shortOpt;
}

std::string OptionDescription::getLongOpt() const
{
    return longOpt;
}

std::string OptionDescription::getDescription() const
{
    return description;
}


REPO_NS_END
