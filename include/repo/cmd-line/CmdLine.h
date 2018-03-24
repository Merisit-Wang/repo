#ifndef INCL_REPO_H3BBE2939_E55C_446F_A2E8_BB4DBC3D1282
#define INCL_REPO_H3BBE2939_E55C_446F_A2E8_BB4DBC3D1282

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
