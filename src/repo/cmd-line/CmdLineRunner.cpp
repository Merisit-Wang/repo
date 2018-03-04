#include "cmd-line/CmdLineRunner.h"
#include "cmd-line/CmdLineParser.h"
#include "options/Option.h"
#include "options/OptionFactory.h"
#include "options/auto/AutoOptionFactory.h"

REPO_NS_BEGIN

int CmdLineRunner::run()
{
    Option* opt = findOption();
    return opt == 0 ? 1 : opt->exec(ROLE(CmdLineParser).getGitCmd());
}

Option* CmdLineRunner::findOption() const
{
    return ROLE(OptionFactory).makeOption(ROLE(CmdLineParser).getOption());
}

REPO_NS_END
