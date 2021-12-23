#include "Pch.h"
#include "Application.h"
#include "Log.h"
#include "glad/glad.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "ChernoEngine/Renderer/BufferLayout.h"

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

    float vertices[3 * 7] = 
    {
      -0.5F, -0.5F, 0.0F, 1.0F, 0.0F, 1.0F, 1.0F,
      0.5F, -0.5F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F,
      0.0F, 0.5F, 0.0F, 1.0F, 1.0F, 0.0F, 1.0F
    };

    uint32_t indices[3] = { 0, 1, 2 };

    vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));
    indexBuffer.reset(IndexBuffer::create(indices, 3));


    BufferLayout vBufferLayout = 
    {
      {FLOAT_3, "position"}, {FLOAT_4, "color"}
    };

    vertexBuffer->setBufferLayout(vBufferLayout);

    uint32_t vIndex = 0;
    for(const BufferElement& vBufferElement : vertexBuffer->getBufferLayout())
    {
      glEnableVertexAttribArray(vIndex);

      glVertexAttribPointer(
        vIndex, 
        vBufferElement.componentCount, 
        convertToOpenGLType(vBufferElement.shaderDataType), 
        vBufferElement.normalized ? GL_TRUE : GL_FALSE, 
        vBufferLayout.getStride(), 
        (const void*)vBufferElement.offset);

      ++vIndex;
    }

    //temporarily hardcode vertex shader here
    std::string vVertexShaderSource = 
    R"(

    #version 330 core
  
    layout(location = 0) in vec3 position;
    layout(location = 1) in vec4 color;

    out vec3 vPosition;
    out vec4 vColor;

    void main()
    {
      vPosition   = position;
      vColor      = color;
      gl_Position = vec4(position, 1.0);
    }
    )";
    // end hardcoded vertex shader

    //temporarily hardcode fragment shader here
    std::string vFragmentShaderSource =
    R"(

    #version 330 core
  
    layout(location = 0) out vec4 color;

    in vec3 vPosition;
    in vec4 vColor;

    void main()
    {
      color = vec4(vPosition * 0.5 + 0.5, 1.0);
      color = vColor;
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


