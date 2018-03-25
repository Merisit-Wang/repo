#include "system/File.h"
#include "system/Dir.h"
#include "debug/Log.h"
#include "system/Run.h"

REPO_NS_BEGIN

void File::createFile(std::string fileName, std::string dir)
{
    std::string cmd = "touch " + fileName;

    try
    {
        Run::cmd(cmd, dir);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        throw ErrorException("Can't create file : " + fileName);
    }
}

REPO_NS_END
