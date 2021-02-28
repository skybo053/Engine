#ifndef WINDOWCLOSEDEVENT_H
#define WINDOWCLOSEDEVENT_H

#include "Event.h"

namespace ChernoEngine
{
  class WindowClosedEvent : public Event
  {
  public:
    WindowClosedEvent();
    ~WindowClosedEvent();

    static EventType getStaticEventType();

    std::string toString() const override;
  };
}

#endif
