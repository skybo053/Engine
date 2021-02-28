#ifndef WINDOWRESIZEDEVENT_H
#define WINDOWRESIZEDEVENT_H

#include "Event.h"

namespace ChernoEngine
{

  class WindowResizedEvent : public Event
  {
  public:
    WindowResizedEvent(int width, int height);
    ~WindowResizedEvent();

    int getWidth() const;
    int getHeight() const;

    std::string toString() const override;

  private:
    int width;
    int height;
  };

}

#endif

