#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "Event.h"
#include "ChernoEngine/Keys.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API KeyEvent : public Event
  {
  public:
    KeyEvent(int pKeyCode, CE_KeyAction pKeyAction, bool pIsRepeat);

    int          getKeyCode() const;
    CE_KeyAction getKeyAction() const;
    bool         isRepeated() const;

    std::string toString() const override;

    static EventType getStaticEventType();

  private:

    //functions
    std::string keyActionToString(CE_KeyAction pKeyAction) const;

    // fields
    int          keyCode;
    CE_KeyAction keyAction;
    bool         isRepeat;
  };

}

#endif