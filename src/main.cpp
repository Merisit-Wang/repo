#include "runtime/RepoRuntime.h"
#include "cmd-line/CmdLine.h"
#include "debug/Log.h"

USING_REPO_NS

int main(int argc, char** argv)
{
    Log::setLogSwitch(true);
    return REPO_RUN(CmdLine(argc, argv));
}
