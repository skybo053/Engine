#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
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

    void pushLayer(Layer* pLayer);
    void pushOverlay(Layer* pOverlay);

  private:
    //functions
    bool onWindowClosedEvent(WindowClosedEvent& pWindowClosedEvent);

    //members
    std::unique_ptr<Window> window;
    bool                    running;
    LayerStack              layerStack;
  };

  Application* createApplication();

}

#endif
