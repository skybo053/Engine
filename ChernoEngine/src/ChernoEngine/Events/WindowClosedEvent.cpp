#include "Pch.h"
#include "WindowClosedEvent.h"

namespace ChernoEngine
{

  WindowClosedEvent::WindowClosedEvent() : Event(EventType::WINDOWCLOSEDEVENT)
  {

  }


  WindowClosedEvent::~WindowClosedEvent()
  {

  }

  
  EventType WindowClosedEvent::getStaticEventType()
  {
    return EventType::WINDOWCLOSEDEVENT;
  }


  std::string WindowClosedEvent::toString() const
  {
    std::string vToString;

    return vToString;
  }

}
