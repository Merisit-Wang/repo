#include "debug/Log.h"
#include "debug/error.h"

#include <stdio.h>

REPO_NS_BEGIN

namespace
{
    static bool logSwitchOn = false;
}

int Log::info(std::string log)
{
    if (!logSwitchOn) return REPO_SUCCESS;
    printf("\033[1m\033[42;37mDONE\033[0m %s\n", log.c_str());
    return REPO_SUCCESS;
}

int Log::warn(std::string log)
{
    if (!logSwitchOn) return REPO_SUCCESS;
    printf("\033[1m\033[43;37mWARN\033[0m %s\n", log.c_str());
    return REPO_SUCCESS;
}

int Log::err(std::string log)
{
    if (!logSwitchOn) return REPO_ERROR;
    printf("\033[1m\033[41;37mERROR\033[0m %s\n", log.c_str());
    return REPO_ERROR;
}

int Log::dbg(std::string log)
{
    if (!logSwitchOn) return REPO_SUCCESS;
    printf("\033[1m\033[44;37mDEBUG\033[0m %s\n", log.c_str());
    return REPO_SUCCESS;
}

void Log::setLogSwitch(bool on)
{
    logSwitchOn = on;
}

REPO_NS_END
