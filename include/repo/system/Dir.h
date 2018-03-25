#ifndef INCL_REPO_HB374D8D9_55BF_4607_86C5_60151ADD2435
#define INCL_REPO_HB374D8D9_55BF_4607_86C5_60151ADD2435

#include "infra/base/repo.h"

#include <iostream>

REPO_NS_BEGIN

struct Dir
{
    static void assertDir(std::string dir);
    static bool hasDir(std::string dir);
    static void mkDir(std::string dir);
    static std::string getPwd();
    static void rmDir(std::string dir);
    static void chDir(std::string dir);
    static bool isRootDir();
};

REPO_NS_END

#endif
