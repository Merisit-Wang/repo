#include "ftesting/FtFixture.h"
#include <string>
#include <sstream>
#include "RepoRuntime.h"
#include "feature/FtCmdLine.h"

FTESTING_NS_BEGIN

CmdLine CmdLineFactory::createWith(const char* args)
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

void CmdLineFactory::converToStringVector(const char* args)
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
