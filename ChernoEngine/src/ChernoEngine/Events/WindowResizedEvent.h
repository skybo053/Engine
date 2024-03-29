#ifndef WINDOWRESIZEDEVENT_H
#define WINDOWRESIZEDEVENT_H

#include "Event.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API WindowResizedEvent : public Event
  {
  public:
    WindowResizedEvent(int width, int height);
    ~WindowResizedEvent();

    int getWidth() const;
    int getHeight() const;

    std::string toString() const override;

    static EventType getStaticEventType();

  private:
    int width;
    int height;
  };

}

#endif

