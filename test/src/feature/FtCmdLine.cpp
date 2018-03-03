#include "ftesting/FtFixture.h"
#include "cmd-line/CmdLine.h"
#include <string>
#include <sstream>
#include "RepoRuntime.h"

USING_REPO_NS

FTESTING_NS_BEGIN

namespace
{
    struct CmdLineFactory
    {
        CmdLine createWith(char* args)
        {
            converToStringVector(args);
            int i = 0;
            for (auto str : strings)
            {
                argv[i] = (char*)str.c_str();
                i++;
            }

            return CmdLine(i, argv);
        }

    private:
        void converToStringVector(char* args)
        {
            std::stringstream stream;
            stream.str(args);
            while(stream)
            {
                std::string str;
                stream >> str;
                strings.push_back(str);
            }
        }

    private:
        std::vector<std::string> strings;
        enum { MAX_CMD_LINE_ARGS = 20 };
        char* argv[MAX_CMD_LINE_ARGS];
    };
}

FIXTURE(FtCmdLine)
{

    TEST("--help")
    {
        CmdLine cmdLine = CmdLineFactory().createWith("repo --help");
        REPO_RUNTIME(CmdLineParser).parse(cmdLine);
        REPO_RUNTIME(CmdLineRunner).run();
    }
};

FTESTING_NS_END
