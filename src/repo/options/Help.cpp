#include <stdio.h>
#include "options/auto/AutoOption.h"

REPO_NS_BEGIN

struct Help;
static AutoOption<Help> help;
struct Help : Option
{
    Help() : shortOpt("-h")
                             , longOpt("--help")
                             , description("show help")
    {
        printf("=====>help create\n");
    }

private:
    OVERRIDE(int exec())
    {
        show();
        return 0;
    }

    OVERRIDE(bool match(std::string option) const)
    {
        if (option == shortOpt || option == longOpt) return true;
        return false;
    }

private:
    void show()
    {
        printf("USAGE:\n");
        printf("    repo <option> [git command]\n");
        printf("\n");
        printf("OPTIONS:\n");
        printf("    --help, -h     show help\n");
    }

private:
    std::string shortOpt;
    std::string longOpt;
    std::string description;
};

REPO_NS_END
