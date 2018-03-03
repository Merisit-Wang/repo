#include "cmd-line/CmdLineParser.h"
#include "cmd-line/CmdLine.h"

REPO_NS_BEGIN

CmdLineParser::CmdLineParser() : option("-h"), gitCmd("git")
{
}

void CmdLineParser::parse(const CmdLine& cmdLine)
{
    auto args = cmdLine.getArgs();
    option = args[0];
    for (int i = 1; i < args.size(); i++)
    {
        gitCmd += " " + args[i];
    }
}

std::string CmdLineParser::getOption() const
{
    return option;
}

std::string CmdLineParser::getGidCmd() const
{
    return gitCmd;
}

REPO_NS_END
