#ifndef INCL_REPO_H35A1C949_16F9_4BEC_931A_FEE6DD4F945F
#define INCL_REPO_H35A1C949_16F9_4BEC_931A_FEE6DD4F945F

#include "infra/base/repo.h"
#include <string>

REPO_NS_BEGIN

struct File
{
    static void create(std::string fileName, std::string dir = "");
    static void writeLen(std::string fileDir, std::string len);
    static std::string readLen(std::string fileDir);
};

REPO_NS_END

#endif
