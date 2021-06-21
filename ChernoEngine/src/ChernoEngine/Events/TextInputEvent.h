#ifndef TEXTINPUTEVENT_H
#define TEXTINPUTEVENT_H

#include "ChernoEngine/Events/Event.h"

namespace ChernoEngine
{

  class CHERNOENGINE_API TextInputEvent : public Event
  {
  public:
    TextInputEvent(char* pText);

    const char* getText() const;
    void setText(char* pText);

    static EventType getStaticEventType();

    std::string toString() const override;

    ~TextInputEvent();
  private:
    char* text;
  };

}


#endif

