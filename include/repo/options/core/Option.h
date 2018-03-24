#ifndef INCL_REPO_H9BC73269_0E01_4D1A_90CC_C6466FA7E594
#define INCL_REPO_H9BC73269_0E01_4D1A_90CC_C6466FA7E594

#include "infra/base/repo.h"
#include "infra/dci/role.h"
#include <string>

REPO_NS_BEGIN

DEFINE_ROLE(Option)
{
    ABSTRACT(int exec(std::string gitCmd));
    ABSTRACT(bool match(std::string option) const);
};

//////////////////////////////////////////////////////////////////////////
struct OptionDescription;

struct CommonOption : Option
{
    CommonOption(OptionDescription& desc);

private:
    OVERRIDE(int exec(std::string gitCmd));
    OVERRIDE(bool match(std::string option) const);

private:
    ABSTRACT(int run(std::string gitCmd));

private:
    const OptionDescription& desc;
};

REPO_NS_END

#endif
