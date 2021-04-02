#include "Pch.h"
#include "MouseClickEvent.h"


namespace ChernoEngine
{

  MouseClickEvent::MouseClickEvent(
    int pXPos, int pYPos, MouseClickEvent::MouseButton pMouseButton, MouseClickEvent::MouseAction pMouseAction) : 
    xPos(pXPos), yPos(pYPos), mouseButton(pMouseButton), mouseAction(pMouseAction), Event(EventType::MOUSECLICKEVENT)
  {

  }


  int MouseClickEvent::getXPos() const
  {
    return xPos;
  }


  int MouseClickEvent::getYPos() const
  {
    return yPos;
  }


  MouseClickEvent::MouseButton MouseClickEvent::getMouseButton() const
  {
    return mouseButton;
  }


  MouseClickEvent::MouseAction MouseClickEvent::getMouseAction() const
  {
    return mouseAction;
  }


  EventType MouseClickEvent::getStaticEventType()
  {
    return EventType::MOUSECLICKEVENT;
  }


  std::string MouseClickEvent::mouseButtonToString(MouseButton pMouseButton) const
  {
    switch(pMouseButton)
    {
      case MouseButton::L_BUTTON:
      {
        return "L_Button";
      }
      case MouseButton::M_BUTTON:
      {
        return "M_Button";
      }
      case MouseButton::R_BUTTON:
      {
        return "R_Button";
      }
      default:
      {
        return "Unknown";
      }
    }
  }


  std::string MouseClickEvent::mouseActionToString(MouseAction pMouseAction) const
  {
    switch(pMouseAction)
    {
      case MouseAction::PRESSED:
      {
        return "Pressed";
      }
      case MouseAction::RELEASED:
      {
        return "Released";
      }
      default:
      {
        return "Unknown";
      }
    }
  }


  std::string MouseClickEvent::toString() const
  {
    std::stringstream vStringStream;

    vStringStream << "X=" << xPos << ", Y=" << yPos << ", MouseButton=" << mouseButtonToString(mouseButton) 
                  << ", MouseAction=" << mouseActionToString(mouseAction);

    return vStringStream.str();
  }

}// end namespace