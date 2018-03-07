#include "options/auto/AutoOption.h"
#include "RepoRuntime.h"

#include <stdio.h>
#include <iostream>
#include <set>

REPO_NS_BEGIN

namespace
{
    struct DescriptionFromat
    {
        DescriptionFromat() : maxSize(0)
        {
            maxOptionLen();
            saveFromatDesc();
        }

        void dump() const
        {
            for (auto str : fromats)
            {
                std::cout << str << std::endl;
            }
        }
    private:
        void maxOptionLen()
        {
            for (auto desc : REPO_RUNTIME(OptionFactory).getDescripions())
            {
                std::string option = desc->getShortOpt() + "," + desc->getLongOpt();
                if (maxSize < option.size()) maxSize = option.size();
            }
        }

        void saveFromatDesc()
        {
            for (auto desc : REPO_RUNTIME(OptionFactory).getDescripions())
            {
                std::string format = "    ";
                std::string blank = "";
                format += desc->getShortOpt() + "," + desc->getLongOpt();
                for (int i = 0; i < (maxSize + 4 - format.size()); i++)
                {
                    blank += " ";
                }
                format += blank + "    " + desc->getDescription();
                fromats.insert(format);
            }
        }

    private:
        std::set<std::string> fromats;
        int maxSize;
    };
}

DEFINE_OPTION(Help, "-h", "--help", "show help")

private:
    OVERRIDE(int run(std::string gitCmd))
    {
        show();
        return 0;
    }

private:
    void show()
    {
        std::cout << "USAGE:"                          << std::endl;
        std::cout << "    repo <option> [git command]" << std::endl;
        std::cout << " "                               << std::endl;
        std::cout << "OPTIONS:"                        << std::endl;
        std::cout << " "                               << std::endl;
        static DescriptionFromat fromat;
        fromat.dump();
    }

END_DEFINE()

REPO_NS_END
