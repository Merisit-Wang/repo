#include "cmd-line/CmdLineRunner.h"
#include "cmd-line/CmdLineParser.h"
#include "options/Option.h"
#include "options/OptionFactory.h"
#include "options/AutoOptionFactory.h"

REPO_NS_BEGIN

int CmdLineRunner::run()
{
    Option* option = findOption();
    if (option == 0) return 1;
    return option->exec();
}

Option* CmdLineRunner::findOption() const
{
    std::string expect = ROLE(CmdLineParser).getOption();
    bool empty = ROLE(OptionFactory).getOptionList().empty();

    for (auto opt : ROLE(OptionFactory).getOptionList())
    {
        Option* createdOption = opt->make();
        if (createdOption->match(expect)) return createdOption;
    }
    return 0;
}

REPO_NS_END
