#ifndef INCL_REPO_H67548266_60AD_46C1_B40A_3B504D26A064
#define INCL_REPO_H67548266_60AD_46C1_B40A_3B504D26A064

#include "infra/base/repo.h"
#include "debug/error.h"
#include <iostream>

REPO_NS_BEGIN

struct Log
{
    static void info(std::string log);
    static void warn(std::string log);
    static void err(std::string log);
    static void dbg(std::string log);
};

#define INFO_LOG(log) Log::info(log)
#define WARN_LOG(log) Log::warn(log)
#define ERR_LOG(log) Log::err(log)
#define DBG_LOG(log) Log::dbg(log)

REPO_NS_END

#endif
