#include "cmd-line/CmdLineRunner.h"
#include "cmd-line/CmdLineParser.h"
#include "options/core/Option.h"
#include "options/core/OptionFactory.h"
#include "options/auto/AutoOptionFactory.h"

REPO_NS_BEGIN

int CmdLineRunner::run()
{
    Option* opt = findOption();
    if (opt == 0)
    {
        ROLE(CmdLineParser).reset();
        opt = findOption();
    }

    return opt->exec(ROLE(CmdLineParser).getGitCmd());
}

Option* CmdLineRunner::findOption() const
{
    return ROLE(OptionFactory).makeOption(ROLE(CmdLineParser).getOption());
}

REPO_NS_END
