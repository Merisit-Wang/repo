#ifndef INCL_REPO_HEBAE797C_5959_4156_81FA_676C739A56EE
#define INCL_REPO_HEBAE797C_5959_4156_81FA_676C739A56EE

#include "ftesting/ftesting.h"
#include "cmd-line/CmdLine.h"

USING_REPO_NS

FTESTING_NS_BEGIN

struct CmdLineFactory
{
    CmdLine createWith(const char* args);

private:
    void converToStringVector(const char* args);
    void free();

private:
    std::vector<std::string> strings;
    enum { MAX_CMD_LINE_ARGS = 20 };
    char* argv[MAX_CMD_LINE_ARGS] = {0};
};

FTESTING_NS_END

#endif
