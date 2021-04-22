#include "Pch.h"
#include "LayerStack.h"

namespace ChernoEngine
{

  LayerStack::LayerStack()
  {

  }
  
  
  void LayerStack::pushLayer(Layer* pLayer)
  {
    layers.emplace(layers.begin(), pLayer);
    pLayer->onAttach();
  }


  void LayerStack::pushOverlay(Layer* pOverLay)
  {
    layers.emplace_back(pOverLay);
    pOverLay->onAttach();
  }


  void LayerStack::popLayer(Layer* pLayer)
  {
    removeLayer(pLayer);
  }


  void LayerStack::popOverlay(Layer* pOverLay)
  {
    removeLayer(pOverLay);
  }


  void LayerStack::removeLayer(Layer* pLayer)
  {
    std::vector<Layer*>::iterator vEnd           = layers.end();
    std::vector<Layer*>::iterator vLayerLocation = std::find(layers.begin(), vEnd, pLayer);

    if(vLayerLocation != vEnd)
    {
      layers.erase(vLayerLocation);
    }
  }


  void LayerStack::updateLayers() const
  {
    for(auto vBegin = layers.begin(), vEnd = layers.end(); vBegin != vEnd; ++vBegin)
    {
      Layer* vLayer = *vBegin;

      vLayer->onUpdate();
    }
  }


  void LayerStack::propagateEvent(Event& pEvent) const
  {
    for(auto vRBegin = layers.rbegin(), vREnd = layers.rend(); vRBegin != vREnd; ++vRBegin)
    {
      Layer* vLayer = *vRBegin;

      vLayer->onEvent(pEvent);

      if(pEvent.getWasHandled())
      {
        break;
      }
    }
  }


  std::vector<Layer*>::iterator LayerStack::begin()
  {
    return layers.begin();
  }


  std::vector<Layer*>::iterator LayerStack::end()
  {
    return layers.end();
  }


  LayerStack::~LayerStack()
  {
    for(Layer* vLayer : layers)
    {
      delete vLayer;

      vLayer = nullptr;
    }

    layers.clear();
  }
}
