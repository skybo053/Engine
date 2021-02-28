#include "pch.h"
#include "Log.h"

namespace ChernoEngine
{
  std::shared_ptr<spdlog::logger> Log::coreLogger;
  std::shared_ptr<spdlog::logger> Log::clientLogger;

  Log::Log()
  {
  }


  Log::~Log()
  {
  }


  void Log::initialize()
  {
    spdlog::set_pattern("%^[%T] %n: %v%$");

    coreLogger   = spdlog::stdout_color_mt("ChernoEngine");
    clientLogger = spdlog::stdout_color_mt("App");

    coreLogger->set_level(spdlog::level::trace);
    clientLogger->set_level(spdlog::level::trace);
  }

  
  std::shared_ptr<spdlog::logger>& Log::getCoreLogger()
  {
    return coreLogger;
  }


  std::shared_ptr<spdlog::logger>& Log::getClientLogger()
  {
    return clientLogger;
  }

}