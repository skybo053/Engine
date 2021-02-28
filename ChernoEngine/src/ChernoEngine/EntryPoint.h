#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef CE_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
  ChernoEngine::Log::initialize();

  CORELOGGER_INFO("Starting engine");
  CORELOGGER_WARN("Initializing loggers");

  CLIENTLOGGER_INFO("ClientLogger initialized");

  auto vApplication = ChernoEngine::createApplication();

  vApplication->run();

  delete vApplication;
}

#endif

#endif //end ENTRYPOINT_H
