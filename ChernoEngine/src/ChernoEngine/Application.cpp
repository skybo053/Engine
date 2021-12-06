#include "Pch.h"
#include "Application.h"
#include "Log.h"
#include "glad/glad.h"
#include "Platform/OpenGL/OpenGLShader.h"

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

    float vertices[9] = 
    {
      -0.5F, -0.5F, 0.0F,
      0.5F, -0.5F, 0.0F,
      0.0F, 0.5F, 0.0F,
    };

    uint32_t indices[3] = { 0, 1, 2 };

    vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));
    indexBuffer.reset(IndexBuffer::create(indices, 3));

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

    //temporarily hardcode vertex shader here
    std::string vVertexShaderSource = 
    R"(

    #version 330 core
  
    layout(location = 0) in vec3 position;

    void main()
    {
      gl_Position = vec4(position, 1.0);
    }
    )";
    // end hardcoded vertex shader

    //temporarily hardcode fragment shader here
    std::string vFragmentShaderSource =
    R"(

    #version 330 core
  
    layout(location = 0) out vec4 color;

    void main()
    {
      color = vec4(0.8, 0.2, 0.3, 1.0);
    }
    )";
    // end hardcoded fragment shader

    shader = std::make_unique<OpenGLShader>(vVertexShaderSource, vFragmentShaderSource);
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
      
      shader->bind();

      glBindVertexArray(vertexArray);
      glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, NULL);

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


