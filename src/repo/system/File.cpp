#include "system/File.h"
#include "system/Dir.h"
#include "debug/Log.h"

REPO_NS_BEGIN

void File::createFile(std::string fileName, std::string dir)
{
    std::string cmd = "touch " + fileName;
    if (system(cmd.c_str()) != 0) throw ErrorException("Can't create file : " + fileName);
}

REPO_NS_END
