#ifndef INCL_REPO_H562ED18A_C3D7_4420_BEB6_3682CA51027B
#define INCL_REPO_H562ED18A_C3D7_4420_BEB6_3682CA51027B

#include "infra/base/repo.h"
#include "infra/dci/role.h"

REPO_NS_BEGIN

struct CmdLineParser;
struct OptionFactory;
struct Option;

DEFINE_ROLE(CmdLineRunner)
{
    int run();

private:
    Option* findOption() const;

private:
    USE_ROLE(CmdLineParser);
    USE_ROLE(OptionFactory);
};

REPO_NS_END

#endif
