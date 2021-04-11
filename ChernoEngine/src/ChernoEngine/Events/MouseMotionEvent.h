#ifndef MOUSEMOTIONEVENT_H
#define MOUSEMOTIONEVENT_H

#include "ChernoEngine/Events/Event.h"
#include "ChernoEngine/Events/MouseClickEvent.h"


namespace ChernoEngine
{
  class MouseMotionEvent : public Event
  {
  public:
    MouseMotionEvent(int pXPos, int pYPos, std::set<MouseClickEvent::MouseButton> pMouseButtonsDown);
    ~MouseMotionEvent();

    int getXPosition() const;
    int getYPosition() const;

    std::set<MouseClickEvent::MouseButton> getMouseButtonsDown() const;
    bool hasMouseButtonsDown() const;
    bool isMouseButtonDown(MouseClickEvent::MouseButton pMouseButton) const;

    std::string toString() const override;

  private:
    //functions
    std::string mouseButtonToString(MouseClickEvent::MouseButton pMouseButton) const;

    //members
    int xPos;
    int yPos;
    std::set<MouseClickEvent::MouseButton> mouseButtonsDown;
  };

}

#endif

