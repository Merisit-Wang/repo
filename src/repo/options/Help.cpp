#include <stdio.h>
#include "options/auto/AutoOption.h"

REPO_NS_BEGIN

DEFINE_OPTION(Help)
{
    Help() : shortOpt("-h")
         , longOpt("--help")
         , description("show help")
    {
    }

private:
    OVERRIDE(int exec(std::string gitCmd))
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
