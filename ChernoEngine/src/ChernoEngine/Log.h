#ifndef LOG_H
#define LOG_H

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace ChernoEngine
{
  class CHERNOENGINE_API Log
  {
  public:
    static void initialize();

    static std::shared_ptr<spdlog::logger>& getCoreLogger();
    static std::shared_ptr<spdlog::logger>& getClientLogger();

  private:
    Log();
    ~Log();

    static std::shared_ptr<spdlog::logger> coreLogger;
    static std::shared_ptr<spdlog::logger> clientLogger;
  }; //end Log class

} //end CharnoEngine namespace

//logging macros
#define CORELOGGER_INFO(...) ChernoEngine::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORELOGGER_WARN(...) ChernoEngine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORELOGGER_DEBUG(...) ChernoEngine::Log::getCoreLogger()->debug(__VA_ARGS__)
#define CORELOGGER_ERROR(...) ChernoEngine::Log::getCoreLogger()->error(__VA_ARGS__)
#define CORELOGGER_TRACE(...) ChernoEngine::Log::getCoreLogger()->trace(__VA_ARGS__)

#define CLIENTLOGGER_INFO(...) ChernoEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define CLIENTLOGGER_WARN(...) ChernoEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define CLIENTLOGGER_DEBUG(...) ChernoEngine::Log::getClientLogger()->debug(__VA_ARGS__)
#define CLIENTLOGGER_ERROR(...) ChernoEngine::Log::getClientLogger()->error(__VA_ARGS__)
#define CLIENTLOGGER_TRACE(...) ChernoEngine::Log::getClientLogger()->trace(__VA_ARGS__)


#endif

