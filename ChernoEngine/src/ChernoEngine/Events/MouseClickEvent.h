#ifndef MOUSECLICKEVENT_H
#define MOUSECLICKEVENT_H

#include "Event.h"
#include "ChernoEngine/MouseButtons.h"


namespace ChernoEngine
{

  class CHERNOENGINE_API MouseClickEvent : public Event
  {
  public:
    
    MouseClickEvent(int pXPos, int pYPos, CE_MouseButtonCode pMouseButton, CE_MouseButtonAction pMouseAction);
    ~MouseClickEvent() = default;

    int getXPos() const;
    int getYPos() const;

    CE_MouseButtonCode   getMouseButton() const;
    CE_MouseButtonAction getMouseAction() const;

    static EventType getStaticEventType();

    std::string toString() const override;

  private:

    //functions
    std::string mouseButtonToString(CE_MouseButtonCode pMouseButton) const;
    std::string mouseActionToString(CE_MouseButtonAction pMouseAction) const;

    //fields
    int xPos;
    int yPos;

    CE_MouseButtonCode   mouseButton;
    CE_MouseButtonAction mouseAction;
  };

}

#endif