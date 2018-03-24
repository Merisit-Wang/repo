#include "cmd-line/CmdLine.h"
#include <iostream>

REPO_NS_BEGIN

CmdLine::CmdLine(int argc, char** argv)
    : args(argv+1, argv+argc+!argc)
{
    args.pop_back();
}

std::vector<std::string> CmdLine::getArgs() const
{
    return args;
}

void CmdLine::dump()
{
    for (auto arg : args)
    {
        std::cout << arg << std::endl;
    }
}

REPO_NS_END
