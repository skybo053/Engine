#include "pch.h"
#include "MouseWheelEvent.h"

namespace ChernoEngine
{

  MouseWheelEvent::MouseWheelEvent(int pHorizontalScroll, int pVerticalScroll, Direction pDirection) 
      : horizontalScroll(pHorizontalScroll), verticalScroll(pVerticalScroll), mouseWheelDirection(pDirection), Event(EventType::MOUSEWHEELEVENT)
  {

  }


  MouseWheelEvent::~MouseWheelEvent()
  {

  }


  EventType MouseWheelEvent::getStaticEventType()
  {
    return EventType::MOUSEWHEELEVENT;
  }

  int MouseWheelEvent::getHorizontalScroll() const
  {
    return horizontalScroll;
  }


  int MouseWheelEvent::getVerticalScroll() const
  {
    return verticalScroll;
  }


  MouseWheelEvent::Direction MouseWheelEvent::getMouseWheelDirection() const
  {
    return mouseWheelDirection;
  }


  std::string MouseWheelEvent::mouseWheelDirectionToString(Direction pDirection) const
  {
    switch(pDirection)
    {
      case Direction::NORMAL:
      {
        return "Normal";
      }
      case Direction::FLIPPED:
      {
        return "Flipped";
      }
      default:
      {
        return "Unknown";
      }
    }
  }


  std::string MouseWheelEvent::toString() const
  {
    std::stringstream vStringStream;

    vStringStream << "HorizontalScroll=" << horizontalScroll << ", VerticalScroll=" << verticalScroll 
                  << ", Direction=" << mouseWheelDirectionToString(mouseWheelDirection);

    return vStringStream.str();
  }

}
