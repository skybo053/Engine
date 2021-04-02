#ifndef EVENT_H
#define EVENT_H

#include "ChernoEngine/Core.h"


namespace ChernoEngine
{
  
  enum class EventType
  {
    NONE,
    WINDOWRESIZED,
    WINDOWCLOSED,
    FOCUS,
    KEYEVENT,
    MOUSECLICKEVENT,
    MOUSEWHEELEVENT,
    MOUSEMOTIONEVENT
  };

  class CHERNOENGINE_API Event
  {
  public:
    Event(EventType pEventType);
    virtual ~Event() = 0;

    EventType getEventType() const;
    std::string getEventTypeName(EventType pEventType) const;

    bool      getWasHandled() const;
    void      setWasHandled(bool pWasHandled);
   
    virtual std::string toString() const = 0; 

  protected:
    EventType eventType;
    bool      wasHandled;
  };


  class CHERNOENGINE_API EventDispatcher
  {
  public:

    EventDispatcher() = delete;

    template<class T>
    static bool dispatch(Event& pEvent, std::function<bool(T)> pFunction)
    {
      if(pEvent.getEventType() == T::getStaticEventType())
      {
        bool vWasHandled = pFunction(static_cast<T&>(pEvent));
      
        pEvent.setWasHandled(vWasHandled);

        return true;
      }

      return false;
    }
  };
  
  
  inline std::ostream& operator<<(std::ostream& pOstream, const Event& pEvent)
  {
    return pOstream << pEvent.getEventTypeName(pEvent.getEventType()) << ": " << pEvent.toString() << std::endl;
  }

}


#endif