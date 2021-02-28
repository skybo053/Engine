#include "pch.h"
#include "KeyEvent.h"

namespace ChernoEngine
{
  
  KeyEvent::KeyEvent(int pKeyCode, KeyAction pKeyAction, bool pIsRepeat) 
      : keyCode(pKeyCode), keyAction(pKeyAction), isRepeat(pIsRepeat), Event(EventType::KEYEVENT)
  {

  }


  int KeyEvent::getKeyCode() const
  {
    return keyCode;
  }


  KeyEvent::KeyAction KeyEvent::getKeyAction() const
  {
    return keyAction;
  }


  bool KeyEvent::isRepeated() const
  {
    return isRepeat;
  }


  EventType KeyEvent::getStaticEventType()
  {
    return EventType::KEYEVENT;
  }


  std::string KeyEvent::keyActionToString(KeyAction pKeyAction) const
  {
    std::string vKeyAction;

    switch(pKeyAction)
    {
      case KeyAction::PRESSED:
      {
        vKeyAction = "KEY_PRESSED";
        break;
      }
      case KeyAction::RELEASED:
      {
        vKeyAction = "KEY_RELEASED";
        break;
      }
      default:
      {
        vKeyAction = "UNKNOWN";
      }
    }

    return vKeyAction;
  }


  std::string KeyEvent::toString() const
  {
    std::stringstream vStringStream;

    vStringStream << "KeyCode=" << keyCode << ", KeyAction=" << keyActionToString(keyAction) << ", is repeated=" << (isRepeat ? "true" : "false");

    return vStringStream.str();
  }

}// end namespace