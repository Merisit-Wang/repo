#include "runtime/RepoRuntime.h"
#include "cmd-line/CmdLine.h"

USING_REPO_NS

int main(int argc, char** argv)
{
    return REPO_RUN(CmdLine(argc, argv));
}
