#ifndef INCL_DCM_H2F0244A6_CC92_4664_ADE3_FF696FD13968
#define INCL_DCM_H2F0244A6_CC92_4664_ADE3_FF696FD13968

#include "infra/base/repo.h"
#include <vector>
#include <string>

REPO_NS_BEGIN

struct CmdLine
{
    CmdLine(int argc, char** argv);

    std::vector<std::string> getArgs() const;

    void dump();

private:
    std::vector<std::string> args;
};

REPO_NS_END

#endif
