#ifndef REPO_CMD_H_15_16
#define REPO_CMD_H_15_16

#include "infra/base/repo.h"
#include <vector>
#include <string>

REPO_NS_BEGIN

struct Cmd
{
    Cmd(int argc, char** argv);

private:
    std::vector<std::string> cmds;
};

REPO_NS_END

#endif
