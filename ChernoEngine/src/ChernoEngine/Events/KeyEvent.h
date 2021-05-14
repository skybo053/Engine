#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "Event.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API KeyEvent : public Event
  {
  public:

    enum class KeyAction
    {
      PRESSED,
      RELEASED
    };

    KeyEvent(int pKeyCode, KeyAction pKeyAction, bool pIsRepeat);

    int       getKeyCode() const;
    KeyAction getKeyAction() const;
    bool      isRepeated() const;

    std::string toString() const override;

    static EventType getStaticEventType();

  private:

    //functions
    std::string keyActionToString(KeyAction pKeyAction) const;

    // fields
    int       keyCode;
    KeyAction keyAction;
    bool      isRepeat;
  };

}

#endif