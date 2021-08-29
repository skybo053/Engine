#include "Pch.h"
#include "MouseClickEvent.h"


namespace ChernoEngine
{

  MouseClickEvent::MouseClickEvent(
    int pXPos, int pYPos, CE_MouseButtonCode pMouseButton, CE_MouseButtonAction pMouseAction) : 
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


  CE_MouseButtonCode MouseClickEvent::getMouseButton() const
  {
    return mouseButton;
  }


  CE_MouseButtonAction MouseClickEvent::getMouseAction() const
  {
    return mouseAction;
  }


  EventType MouseClickEvent::getStaticEventType()
  {
    return EventType::MOUSECLICKEVENT;
  }


  std::string MouseClickEvent::mouseButtonToString(CE_MouseButtonCode pMouseButton) const
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
      default:
      {
        return "Unknown";
      }
    }
  }


  std::string MouseClickEvent::mouseActionToString(CE_MouseButtonAction pMouseAction) const
  {
    switch(pMouseAction)
    {
      case CE_BUTTON_PRESSED:
      {
        return "Pressed";
      }
      case CE_BUTTON_RELEASED:
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