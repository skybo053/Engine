#include "Pch.h"
#include "WindowClosedEvent.h"

namespace ChernoEngine
{

  WindowClosedEvent::WindowClosedEvent() : Event(EventType::WINDOWCLOSED)
  {

  }


  WindowClosedEvent::~WindowClosedEvent()
  {

  }

  
  EventType WindowClosedEvent::getStaticEventType()
  {
    return EventType::WINDOWCLOSED;
  }


  std::string WindowClosedEvent::toString() const
  {
    std::string vToString;

    return vToString;
  }

}
