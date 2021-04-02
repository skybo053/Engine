#include "pch.h"
#include "Layer.h"

namespace ChernoEngine
{
  Layer::Layer(const std::string& pLayerName) : layerName(pLayerName)
  {

  }
  
  
  void Layer::onAttach()
  {
    return;
  }


  void Layer::onDetach()
  {
    return;
  }


  void Layer::onUpdate()
  {
    return;
  }


  void Layer::onEvent(Event& pEvent)
  {
    return;
  }


  const std::string& Layer::getName() const
  {
    return layerName;
  }


  Layer::~Layer()
  {

  }
}
