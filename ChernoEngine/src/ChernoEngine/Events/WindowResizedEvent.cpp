#include "pch.h"
#include "WindowResizedEvent.h"


namespace ChernoEngine
{

  WindowResizedEvent::WindowResizedEvent(int width, int height) : width(width), height(height), Event(EventType::WINDOWRESIZED)
  {

  }


  WindowResizedEvent::~WindowResizedEvent()
  {

  }


  int WindowResizedEvent::getWidth() const
  {
    return width;
  }


  int WindowResizedEvent::getHeight() const
  {
    return height;
  }


  std::string WindowResizedEvent::toString() const
  {
    std::stringstream vStringStream;

    vStringStream << "Width=" << width << ", Height=" << height;

    return vStringStream.str();
  }

}
