#include "Pch.h"
#include "MouseMotionEvent.h"


namespace ChernoEngine
{

  MouseMotionEvent::MouseMotionEvent(int pXPos, int pYPos, std::set<MouseClickEvent::MouseButton> pMouseButtonsDown) 
      : xPos(pXPos), yPos(pYPos), mouseButtonsDown(pMouseButtonsDown), Event(EventType::MOUSEMOTIONEVENT)
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


  std::set<MouseClickEvent::MouseButton> MouseMotionEvent::getMouseButtonsDown() const
  {
    return mouseButtonsDown;
  }


  bool MouseMotionEvent::hasMouseButtonsDown() const
  {
    return !mouseButtonsDown.empty();
  }


  bool MouseMotionEvent::isMouseButtonDown(MouseClickEvent::MouseButton pMouseButton) const
  {
    return mouseButtonsDown.find(pMouseButton) != mouseButtonsDown.end();
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
      default:
      {
        return "Unknown";
      }
    }
  }


  std::string MouseMotionEvent::toString() const
  {
    std::stringstream vStringStream;

    vStringStream << "X=" << xPos << ", Y=" << yPos << ", Mouse Buttons Down=";

    if(hasMouseButtonsDown())
    {
      for(MouseClickEvent::MouseButton vMouseButton : mouseButtonsDown)
      {
        vStringStream << mouseButtonToString(vMouseButton) << " ";
      }
    }
    else
    {
      vStringStream << mouseButtonToString(MouseClickEvent::MouseButton::NONE);
    }

    return vStringStream.str();
  }

  EventType MouseMotionEvent::getStaticEventType()
  {
    return EventType::MOUSEMOTIONEVENT;
  }

}// end namespace