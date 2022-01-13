#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "ChernoEngine/Events/WindowClosedEvent.h"
#include "ChernoEngine/ImGui/ImGuiLayer.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Renderer/Buffer.h"
#include "ChernoEngine/Renderer/VertexArray.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API Application
  {
  public:
    Application();
    virtual ~Application();

    void run();
    void onEvent(Event& pEvent);

    void pushLayer(Layer* pLayer);
    void pushOverlay(Layer* pOverlay);

    int getWindowWidth() const;
    int getWindowHeight() const;

    const static Application& getApplicationRef();

    const Window& getWindow() const;

  private:
    //functions
    bool onWindowClosedEvent(WindowClosedEvent& pWindowClosedEvent);

    //members
    std::unique_ptr<Window>     window;
    ImGuiLayer*                 imGuiLayer;
    bool                        running;
    LayerStack                  layerStack;
    
    static Application*         application;

    std::shared_ptr<VertexBuffer> vertexBuffer;
    std::shared_ptr<IndexBuffer>  indexBuffer;
    std::shared_ptr<VertexArray>  vertexArray;
    std::shared_ptr<Shader>       shader;

    std::shared_ptr<VertexArray> squareVertexArray;
  };

  Application* createApplication();

}

#endif
