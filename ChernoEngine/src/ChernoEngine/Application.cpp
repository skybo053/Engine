#include "pch.h"
#include "Application.h"
#include "Log.h"

#include <sdl/SDL.h>
#include <sdl/SDL_opengl.h>

namespace ChernoEngine
{

  Application::Application() : 
      window(std::unique_ptr<Window>(Window::create(WindowProps()))),
      running(true)
  {
    window->setEventCallback(
        std::bind(&Application::onEvent, this, std::placeholders::_1));
  }


  Application::~Application()
  {

  }


  void Application::run()
  {
    while(running)
    {
      glClearColor(1,0,1,1);
      glClear(GL_COLOR_BUFFER_BIT);
      window->onUpdate();
    }
  }

  
  void Application::onEvent(Event& pEvent)
  {
    EventDispatcher::dispatch<WindowClosedEvent>(pEvent, std::bind(&Application::onWindowClosedEvent, this, std::placeholders::_1));
    CORELOGGER_INFO("{0}", pEvent);
  }


  bool Application::onWindowClosedEvent(WindowClosedEvent& pWindowClosedEvent)
  {
    running = false;

    return true;
  }

}


