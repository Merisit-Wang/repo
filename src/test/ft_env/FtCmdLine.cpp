#include "ftesting/FtFixture.h"
#include "runtime/RepoRuntime.h"
#include "ft_env/FtCmdLine.h"

#include <string>
#include <sstream>

FTESTING_NS_BEGIN

CmdLine CmdLineFactory::createWith(const char* args)
{
    converToStringVector(args);
    int i = 0;
    for (auto str : strings)
    {
        argv[i] = new char[MAX_CMD_LINE_ARGS];
        strcpy(argv[i], str.c_str());
        i++;
    }

    CmdLine cmd(i, argv);
    free();

    return cmd;
}

void CmdLineFactory::free()
{
    for (int i = 0; i < MAX_CMD_LINE_ARGS; i++)
    {
        if (argv[i] != 0) delete argv[i];
    }
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

CmdLine createCmd(const char* args)
{
    return CmdLineFactory().createWith(args);
}

FTESTING_NS_END
