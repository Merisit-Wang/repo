#include "options/Help.h"
#include <stdio.h>
#include "options/AutoOption.h"

REPO_NS_BEGIN

DEFINE_OPTION(Help)
{
    Help() : shortOpt("-h")
                             , longOpt("--help")
                             , description("show help")
    {
        printf("=====> help create\n");
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

//Help() : shortOpt("-h")
//                         , longOpt("--help")
//                         , description("show help")
//{
//}
//
//int Help::exec()
//{
//    show();
//    return 0;
//}
//
//bool Help::match(std::string option) const
//{
//    if (option == shortOpt || option == longOpt) return true;
//    return false;
//}
//
//void Help::show()
//{
//    printf("USAGE:\n");
//    printf("    repo <option> [git command]\n");
//    printf("\n");
//    printf("OPTIONS:\n");
//    printf("    --help, -h     show help\n");
//}

REPO_NS_END
