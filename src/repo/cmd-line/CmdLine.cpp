#include "cmd-line/CmdLine.h"
#include <iostream>

REPO_NS_BEGIN

CmdLine::CmdLine(int argc, const char** argv)
    : args(argv+1, argv+argc+!argc)
{
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
