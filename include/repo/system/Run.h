#ifndef INCL_REPO_H0428E158_C1AB_4225_B55E_1D10BF292ACB
#define INCL_REPO_H0428E158_C1AB_4225_B55E_1D10BF292ACB

#include "infra/base/repo.h"
#include <string>

REPO_NS_BEGIN

struct Run
{
    static void cmd(std::string cmd, std::string dir = "");
};

REPO_NS_END

#endif
