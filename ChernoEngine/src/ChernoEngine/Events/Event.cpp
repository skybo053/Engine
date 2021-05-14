#include "Pch.h"
#include "Event.h"


namespace ChernoEngine
{

  Event::Event(EventType pEventType) : eventType(pEventType), wasHandled(false)
  {

  }

  Event::~Event()
  {

  }

  EventType Event::getEventType() const
  {
    return eventType;
  }

  bool Event::getWasHandled() const
  {
    return wasHandled;
  }

  void Event::setWasHandled(bool pWasHandled)
  {
    wasHandled = pWasHandled;
  }

  std::string Event::getEventTypeName(EventType pEventType) const
  {
    switch(pEventType)
    {
      case EventType::WINDOWRESIZEDEVENT:
      {
        return "WindowResizedEvent";
      }
      case EventType::WINDOWCLOSEDEVENT:
      {
        return "WindowClosedEvent";
      }
      case EventType::FOCUS:
      {
        return "FocusEvent";
      }
      case EventType::KEYEVENT:
      {
        return "KeyEvent";
      }
      case EventType::MOUSECLICKEVENT:
      {
        return "MouseClickEvent";
      }
      case EventType::MOUSEWHEELEVENT:
      {
        return "MouseWheelEvent";
      }
      case EventType::MOUSEMOTIONEVENT:
      {
        return "MouseMotionEvent";
      }
      case EventType::TEXTINPUTEVENT:
      {
        return "TextInputEvent";
      }
      default:
      {
        return "UnknownEvent";
      }
    }
  }

} // end namespace

