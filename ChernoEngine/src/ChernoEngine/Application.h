#ifndef APPLICATION_H
#define APPLICATION_H

#include "pch.h"
#include "Core.h"
#include "Window.h"
#include "ChernoEngine/Events/WindowClosedEvent.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API Application
  {
  public:
    Application();
    virtual ~Application();

    void run();

    void onEvent(Event& pEvent);

  private:
    //functions
    bool onWindowClosedEvent(WindowClosedEvent& pWindowClosedEvent);

    //members
    std::unique_ptr<Window> window;
    bool running;
  };

  Application* createApplication();

}

#endif
