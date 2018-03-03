#ifndef INCL_REPO_H5C3881BA_96C7_4EB5_9AAF_BFDB52D98EE2
#define INCL_REPO_H5C3881BA_96C7_4EB5_9AAF_BFDB52D98EE2

#include "infra/base/repo.h"
#include <string>
#include "infra/dci/role.h"

REPO_NS_BEGIN

struct CmdLine;

DEFINE_ROLE(CmdLineParser)
{
    CmdLineParser();

    std::string getOption() const;
    std::string getGidCmd() const;

    void parse(const CmdLine& cmdLine);

private:
    std::string option;
    std::string gitCmd;
};

REPO_NS_END

#endif
