#include "pch.h"
#include "MouseMotionEvent.h"


namespace ChernoEngine
{

  MouseMotionEvent::MouseMotionEvent(int pXPos, int pYPos, MouseClickEvent::MouseButton pMouseButtonPressed) 
      : xPos(pXPos), yPos(pYPos), mouseButton(pMouseButtonPressed), Event(EventType::MOUSEMOTIONEVENT)
  {

  }


  MouseMotionEvent::~MouseMotionEvent()
  {

  }


  int MouseMotionEvent::getXPosition() const
  {
    return xPos;
  }


  int MouseMotionEvent::getYPosition() const
  {
    return yPos;
  }


  MouseClickEvent::MouseButton MouseMotionEvent::getMouseButtonPressed() const
  {
    return mouseButton;
  }


  std::string MouseMotionEvent::mouseButtonToString(MouseClickEvent::MouseButton pMouseButton) const
  {
    switch(pMouseButton)
    {
      case MouseClickEvent::MouseButton::L_BUTTON:
      {
        return "L_Button";
      }
      case MouseClickEvent::MouseButton::M_BUTTON:
      {
        return "M_Button";
      }
      case MouseClickEvent::MouseButton::R_BUTTON:
      {
        return "R_Button";
      }
      case MouseClickEvent::MouseButton::NONE:
      {
        return "None";
      }
    }
  }


  std::string MouseMotionEvent::toString() const
  {
    std::stringstream vStringStream;

    vStringStream << "X=" << xPos << ", Y=" << yPos << ", MouseButton=" << mouseButtonToString(mouseButton);

    return vStringStream.str();
  }

}// end namespace