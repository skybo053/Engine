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
  
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    float vertices[3 * 3] = 
    {
      -0.5F, -0.5F, 0.0F,
      0.5F, -0.5F, 0.0F,
      0.0F, 0.5F, 0.0F,
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

    int indices[3] = {0, 1, 2};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
  }


  Application::~Application()
  {

  }


  void Application::run()
  {
    while(running)
    {
      glClearColor(0.1F, 0.1F, 0.1F, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      
      glBindVertexArray(vertexArray);
      glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);

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
    return *application;
  }


  const Window& Application::getWindow() const
  {
    Window& vWindow = static_cast<Window&>(*window.get());

    return vWindow;
  }
}


