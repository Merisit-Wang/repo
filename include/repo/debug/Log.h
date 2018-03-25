#ifndef INCL_REPO_H67548266_60AD_46C1_B40A_3B504D26A064
#define INCL_REPO_H67548266_60AD_46C1_B40A_3B504D26A064

#include "infra/base/repo.h"
#include "debug/error.h"
#include <iostream>

REPO_NS_BEGIN

struct Log
{
    static int info(std::string log);
    static int warn(std::string log);
    static int err(std::string log);
    static int dbg(std::string log);
    static void setLogSwitch(bool on = false);
};

#define INFO_LOG(log) Log::info(log)
#define WARN_LOG(log) Log::warn(log)
#define ERR_LOG(log) Log::err(log)
#define DBG_LOG(log) Log::dbg(log)

struct ErrorException : public std::exception
{
    ErrorException(std::string message) : message(message) {}

   const char* what()const throw()
   {
       ERR_LOG(message);
       return "";
   }

private:
   std::string message;
};

REPO_NS_END

#endif
