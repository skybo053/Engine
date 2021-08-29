#ifndef MOUSEMOTIONEVENT_H
#define MOUSEMOTIONEVENT_H

#include "ChernoEngine/Events/Event.h"
#include "ChernoEngine/Events/MouseClickEvent.h"
#include "ChernoEngine/MouseButtons.h"

namespace ChernoEngine
{
  class CHERNOENGINE_API MouseMotionEvent : public Event
  {
  public:
    MouseMotionEvent(int pXPos, int pYPos, std::set<CE_MouseButtonCode> pMouseButtonsDown);
    ~MouseMotionEvent();

    int getXPosition() const;
    int getYPosition() const;

    std::set<CE_MouseButtonCode> getMouseButtonsDown() const;
    bool hasMouseButtonsDown() const;
    bool isMouseButtonDown(CE_MouseButtonCode pMouseButton) const;

    std::string toString() const override;

    static EventType getStaticEventType();

  private:
    //functions
    std::string mouseButtonToString(CE_MouseButtonCode pMouseButton) const;

    //members
    int xPos;
    int yPos;
    std::set<CE_MouseButtonCode> mouseButtonsDown;
  };

}

#endif

