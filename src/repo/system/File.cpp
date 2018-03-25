#include "system/File.h"
#include "system/Dir.h"
#include "debug/Log.h"
#include "system/Run.h"

#include <iosfwd>
#include <fstream>

REPO_NS_BEGIN

void File::create(std::string fileName, std::string dir)
{
    try
    {
        Run::cmd("touch " + fileName, dir);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        throw ErrorException("Can't create file : " + fileName);
    }
}

void File::writeLen(std::string fileDir, std::string len)
{
    try
    {
        Run::cmd("echo \"" + len + "\" >> " + fileDir);
    }
    catch(ErrorException& ex)
    {
        ex.what();
        throw ErrorException("File write error : " + fileDir);
    }
}

std::string File::readLen(std::string fileDir)
{
    std::ifstream infile;
    infile.open(fileDir.c_str());
    if (!infile.is_open()) throw ErrorException("File read error : " + fileDir);
    std::string len;
    infile >> len;
    return len;
}

REPO_NS_END
