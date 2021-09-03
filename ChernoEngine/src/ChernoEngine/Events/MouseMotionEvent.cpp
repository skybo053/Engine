#include "Pch.h"
#include "MouseMotionEvent.h"


namespace ChernoEngine
{

  MouseMotionEvent::MouseMotionEvent(int pXPos, int pYPos, std::set<CE_MouseButtonCode> pMouseButtonsDown) 
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


  std::set<CE_MouseButtonCode> MouseMotionEvent::getMouseButtonsDown() const
  {
    return mouseButtonsDown;
  }


  bool MouseMotionEvent::hasMouseButtonsDown() const
  {
    return !mouseButtonsDown.empty();
  }


  bool MouseMotionEvent::isMouseButtonDown(CE_MouseButtonCode pMouseButton) const
  {
    return mouseButtonsDown.find(pMouseButton) != mouseButtonsDown.end();
  }


  std::string MouseMotionEvent::mouseButtonToString(CE_MouseButtonCode pMouseButton) const
  {
    switch(pMouseButton)
    {
      case CE_BUTTON_LEFT:
      {
        return "L_Button";
      }
      case CE_BUTTON_MIDDLE:
      {
        return "M_Button";
      }
      case CE_BUTTON_RIGHT:
      {
        return "R_Button";
      }
      case CE_BUTTON_NONE:
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
      for(CE_MouseButtonCode vMouseButton : mouseButtonsDown)
      {
        vStringStream << mouseButtonToString(vMouseButton) << " ";
      }
    }
    else
    {
      vStringStream << mouseButtonToString(CE_BUTTON_NONE);
    }

    return vStringStream.str();
  }

  EventType MouseMotionEvent::getStaticEventType()
  {
    return EventType::MOUSEMOTIONEVENT;
  }

}// end namespace