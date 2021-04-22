#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Layer.h"


namespace ChernoEngine
{

  class CHERNOENGINE_API ImGuiLayer : public Layer
  {
  public:
    ImGuiLayer(const std::string& pLayerName, int displayWidth, int displayHeight);
    ~ImGuiLayer();

    void onAttach() override;
    void onDetach() override;

    void onUpdate() override;
    void onEvent(Event& pEvent) override;

    int getDisplayWidth() const;
    int getDisplayHeight() const;

  private:
    int displayWidth;
    int displayHeight;
    float time = 0.0F;
  };

}


#endif