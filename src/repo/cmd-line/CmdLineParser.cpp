#include "cmd-line/CmdLineParser.h"
#include "cmd-line/CmdLine.h"

REPO_NS_BEGIN

namespace
{
    std::string fetchOption(std::vector<std::string>& args)
    {
        std::string option;
        std::string first = args.front();

        if (first.empty()) return option;
        if (first[0] == '-' || first[1] == '-')
        {
            option = first;
            args.erase(args.begin());
        }

        return option;
    }

    std::string fetchGitCmd(std::vector<std::string>& args)
    {
        std::string gitCmd;
        if (args.empty()) return gitCmd;
        for (int i = 0; i < args.size(); i++)
        {
            gitCmd += args[i];
            if ((i + 1) >= args.size()) break;
            gitCmd += " ";
        }

        return gitCmd;
    }
}

void CmdLineParser::parse(const CmdLine& cmdLine)
{
    auto args = cmdLine.getArgs();
    if (args.empty()) return ;

    option = fetchOption(args);
    gitCmd = fetchGitCmd(args);
}

std::string CmdLineParser::getOption() const
{
    return option;
}

std::string CmdLineParser::getGitCmd() const
{
    return gitCmd;
}

REPO_NS_END
