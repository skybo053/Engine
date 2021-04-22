#include "Pch.h"
#include "Application.h"
#include "Log.h"
#include "glad/glad.h"


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
      
      layerStack.updateLayers();

      window->onUpdate();
    }
  }

  
  void Application::onEvent(Event& pEvent)
  {
    EventDispatcher::dispatch<WindowClosedEvent>(pEvent, std::bind(&Application::onWindowClosedEvent, this, std::placeholders::_1));
    CORELOGGER_INFO("{0}", pEvent);

    layerStack.propagateEvent(pEvent);
  }


  bool Application::onWindowClosedEvent(WindowClosedEvent& pWindowClosedEvent)
  {
    running = false;

    return true;
  }


  void Application::pushLayer(Layer* pLayer)
  {
    layerStack.pushLayer(pLayer);
  }


  void Application::pushOverlay(Layer* pOverlay)
  {
    layerStack.pushOverlay(pOverlay);
  }


  int Application::getWindowWidth() const
  {
    return window->getWidth();
  }


  int Application::getWindowHeight() const
  {
    return window->getHeight();
  }
}


