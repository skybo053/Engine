#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Pch.h"
#include "Layer.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API LayerStack
  {
  public:
    LayerStack();
    ~LayerStack();

    void pushLayer(Layer* pLayer);
    void pushOverlay(Layer* pOverLay);
    void popLayer(Layer* pLayer);
    void popOverlay(Layer* pOverLay);

    void updateLayers() const;
    void propagateEvent(Event& pEvent) const;

    std::vector<Layer*>::iterator begin();
    std::vector<Layer*>::iterator end();

  private:
    //functions
    void removeLayer(Layer* pLayer);

    //members
    std::vector<Layer*> layers;
  };

}

#endif

