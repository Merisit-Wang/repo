#include "debug/Log.h"

REPO_NS_BEGIN

void Log::info(std::string log)
{
    std::cout << "[INFO]" << log << std::endl;
}

void Log::warn(std::string log)
{
    std::cout << "[WARN]" << log << std::endl;
}

void Log::err(std::string log)
{
    std::cout << "[ERROR]" << log << std::endl;
}

void Log::dbg(std::string log)
{
    std::cout << "[DEBUG]" << log << std::endl;
}

REPO_NS_END
