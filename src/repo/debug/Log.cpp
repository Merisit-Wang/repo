#include "debug/Log.h"

#include <stdio.h>

REPO_NS_BEGIN

void Log::info(std::string log)
{
    printf("\033[1m\033[42;37mDONE\033[0m %s\n", log.c_str());
}

void Log::warn(std::string log)
{
    printf("\033[1m\033[43;37mWARN\033[0m %s\n", log.c_str());
}

void Log::err(std::string log)
{
    printf("\033[1m\033[41;37mERROR\033[0m %s\n", log.c_str());
}

void Log::dbg(std::string log)
{
    printf("\033[1m\033[44;37mDEBUG\033[0m %s\n", log.c_str());
}

REPO_NS_END
