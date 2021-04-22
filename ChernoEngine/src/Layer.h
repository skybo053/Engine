#ifndef LAYER_H
#define LAYER_H

#include "ChernoEngine/Events/Event.h"


namespace ChernoEngine
{
  class CHERNOENGINE_API Layer
  {
  public:
    Layer(const std::string& pLayerName);
    virtual ~Layer();

    virtual void onAttach();
    virtual void onDetach();
    virtual void onUpdate();
    virtual void onEvent(Event& pEvent);

    const std::string& getName() const;

  protected:
    std::string layerName;
  };

}

#endif