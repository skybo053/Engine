#include "Pch.h"
#include "KeyEvent.h"

namespace ChernoEngine
{
  
  KeyEvent::KeyEvent(int pKeyCode, CE_KeyAction pKeyAction, bool pIsRepeat) 
      : keyCode(pKeyCode), keyAction(pKeyAction), isRepeat(pIsRepeat), Event(EventType::KEYEVENT)
  {

  }


  int KeyEvent::getKeyCode() const
  {
    return keyCode;
  }


  CE_KeyAction KeyEvent::getKeyAction() const
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


  std::string KeyEvent::keyActionToString(CE_KeyAction pKeyAction) const
  {
    std::string vKeyAction;

    switch(pKeyAction)
    {
      case CE_KEY_PRESSED:
      {
        vKeyAction = "KEY_PRESSED";
        break;
      }
      case CE_KEY_RELEASED:
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