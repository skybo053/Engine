#include "Pch.h"
#include "TextInputEvent.h"


namespace ChernoEngine
{

  TextInputEvent::TextInputEvent(char* pText) : text(pText), Event(EventType::TEXTINPUTEVENT) {}


  const char* TextInputEvent::getText() const
  {
    return text;
  }


  void TextInputEvent::setText(char* pText)
  {
    text = pText;
  }


  EventType TextInputEvent::getStaticEventType()
  {
    return EventType::TEXTINPUTEVENT;
  }


  std::string TextInputEvent::toString() const
  {
    std::stringstream vStringStream;

    vStringStream << "Text=" << text;

    return vStringStream.str();
  }


  TextInputEvent::~TextInputEvent()
  {

  }

}