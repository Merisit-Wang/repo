#ifndef INCL_REPO_H1FE79C66_BDB2_4767_B11B_36ED3BCB8DA5
#define INCL_REPO_H1FE79C66_BDB2_4767_B11B_36ED3BCB8DA5

#include "infra/base/repo.h"
#include <string>

REPO_NS_BEGIN

struct OptionDescription
{
    OptionDescription();
    OptionDescription(std::string shortOpt, std::string longOpt, std::string description);

    bool thisOption(std::string option) const;
    bool isNull() const;

    std::string getShortOpt() const;
    std::string getLongOpt() const;
    std::string getDescription() const;

private:
    std::string shortOpt;
    std::string longOpt;
    std::string description;
};

REPO_NS_END

#endif
