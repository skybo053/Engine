#ifndef MOUSEWHEELEVENT_H
#define MOUSEWHEELEVENT_H

#include "Event.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API MouseWheelEvent : public Event
  {
  public:

    enum class Direction
    {
      NORMAL,
      FLIPPED
    };

    MouseWheelEvent(int pHorizontalScroll, int pVerticalScroll, Direction pMouseWheelDirection);
    ~MouseWheelEvent();

    int getHorizontalScroll() const;
    int getVerticalScroll() const;
    Direction getMouseWheelDirection() const;

    static EventType getStaticEventType();

    
    std::string toString() const override;

  private:
    //functions
    std::string mouseWheelDirectionToString(Direction pDirection) const;

    //members
    int horizontalScroll;
    int verticalScroll;
    Direction mouseWheelDirection;
  };

}


#endif