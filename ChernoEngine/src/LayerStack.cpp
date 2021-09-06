#include "Pch.h"
#include "LayerStack.h"

namespace ChernoEngine
{

  LayerStack::LayerStack()
  {

  }
  
  
  void LayerStack::pushLayer(Layer* pLayer)
  {
    layers.emplace(layers.begin() + layerInsertIndex, pLayer);
    pLayer->onAttach();
    ++layerInsertIndex;
  }


  void LayerStack::pushOverlay(Layer* pOverLay)
  {
    layers.emplace_back(pOverLay);
    pOverLay->onAttach();
  }


  bool LayerStack::popLayer(Layer* pLayer)
  {
    if(removeLayer(pLayer))
    {
      --layerInsertIndex;
      return true;
    }

    return false;
  }


  void LayerStack::popOverlay(Layer* pOverLay)
  {
    removeLayer(pOverLay);
  }


  bool LayerStack::removeLayer(Layer* pLayer)
  {
    bool                          vLayerRemoved  = false;
    std::vector<Layer*>::iterator vEnd           = layers.end();
    std::vector<Layer*>::iterator vLayerLocation = std::find(layers.begin(), vEnd, pLayer);

    if(vLayerLocation != vEnd)
    {
      layers.erase(vLayerLocation);
      vLayerRemoved = true;
    }

    return vLayerRemoved;
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
