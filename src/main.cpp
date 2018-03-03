#include <string>
#include <stdio.h>
#include "RepoRuntime.h"
#include "options/OptionMake.h"
#include "cut/cut.hpp"

USING_REPO_NS

int main(int argc, char** argv)
{
    for (auto opt : REPO_RUNTIME(OptionFactory).getOptionList())
    {
        opt->make()->exec();
    }

    return cut::run_all_tests(argc, argv);
}
