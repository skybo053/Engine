#include "Pch.h"
#include "Application.h"
#include "Log.h"
#include "glad/glad.h"


namespace ChernoEngine
{
  Application* Application::application = nullptr;

  Application::Application() : 
      window(std::unique_ptr<Window>(Window::create(WindowProps()))),
      imGuiLayer(new ImGuiLayer("ImGuiLayer", window->getWidth(), window->getHeight())),
      running(true)
  {
    application = this;

    window->setEventCallback(
        std::bind(&Application::onEvent, this, std::placeholders::_1));

    layerStack.pushOverlay(imGuiLayer);
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

      //ImGui specific
      imGuiLayer->begin();

      for(Layer* vLayer : layerStack)
      {
        vLayer->onImGuiRender();
      }

      imGuiLayer->end();
      // end ImGui specific

      window->onUpdate();
    }
  }

  
  void Application::onEvent(Event& pEvent)
  {
    EventDispatcher::dispatch<WindowClosedEvent>(pEvent, std::bind(&Application::onWindowClosedEvent, this, std::placeholders::_1));
    //CORELOGGER_INFO("{0}", pEvent);

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


  const Application& Application::getApplicationRef()
  {
    return static_cast<Application&>(*application);
  }


  const Window& Application::getWindow() const
  {
    Window& vWindow = static_cast<Window&>(*window.get());

    return vWindow;
  }
}


