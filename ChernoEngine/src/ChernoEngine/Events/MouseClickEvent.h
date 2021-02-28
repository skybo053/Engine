#ifndef MOUSECLICKEVENT_H
#define MOUSECLICKEVENT_H

#include "Event.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API MouseClickEvent : public Event
  {
  public:

    enum class MouseButton
    {
      NONE,
      L_BUTTON,
      M_BUTTON,
      R_BUTTON
    };

    enum class MouseAction
    {
      PRESSED,
      RELEASED
    };

    MouseClickEvent(int pXPos, int pYPos, MouseButton pMouseButton, MouseAction pMouseAction);
    ~MouseClickEvent() = default;

    int getXPos() const;
    int getYPos() const;

    MouseButton getMouseButton() const;
    MouseAction getMouseAction() const;

    static EventType getStaticEventType();

    std::string toString() const override;

  private:

    //functions
    std::string mouseButtonToString(MouseButton pMouseButton) const;
    std::string mouseActionToString(MouseAction pMouseAction) const;

    //fields
    int xPos;
    int yPos;

    MouseButton mouseButton;
    MouseAction mouseAction;
  };

}

#endif