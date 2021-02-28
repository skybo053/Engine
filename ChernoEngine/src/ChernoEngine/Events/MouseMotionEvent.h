#ifndef MOUSEMOTIONEVENT_H
#define MOUSEMOTIONEVENT_H

#include "ChernoEngine/Events/Event.h"
#include "ChernoEngine/Events/MouseClickEvent.h"


namespace ChernoEngine
{
  class MouseMotionEvent : public Event
  {
  public:
    MouseMotionEvent(int pXPos, int pYPos, MouseClickEvent::MouseButton);
    ~MouseMotionEvent();

    int getXPosition() const;
    int getYPosition() const;
    MouseClickEvent::MouseButton getMouseButtonPressed() const;

    std::string toString() const override;

  private:
    //functions
    std::string mouseButtonToString(MouseClickEvent::MouseButton pMouseButton) const;

    //members
    int xPos;
    int yPos;
    MouseClickEvent::MouseButton mouseButton;
  };

}

#endif

