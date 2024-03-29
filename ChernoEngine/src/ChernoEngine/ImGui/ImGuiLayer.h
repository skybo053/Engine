#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Layer.h"

#include "ChernoEngine/Events/KeyEvent.h"
#include "ChernoEngine/Events/MouseClickEvent.h"
#include "ChernoEngine/Events/MouseMotionEvent.h"
#include "ChernoEngine/Events/MouseWheelEvent.h"
#include "ChernoEngine/Events/WindowClosedEvent.h"
#include "ChernoEngine/Events/WindowResizedEvent.h"
#include "ChernoEngine/Events/TextInputEvent.h"


namespace ChernoEngine
{

  class CHERNOENGINE_API ImGuiLayer : public Layer
  {
  public:
    ImGuiLayer(const std::string& pLayerName, int displayWidth, int displayHeight);
    ~ImGuiLayer();

    void onAttach() override;
    void onDetach() override;

    void onImGuiRender() override;

    void begin();
    void end();

    int getDisplayWidth() const;
    int getDisplayHeight() const;

  private:


    // variables
    int displayWidth;
    int displayHeight;
    uint64_t time = 0;
  };

}


#endif