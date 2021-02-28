#ifndef WINDOW_H
#define WINDOW_H

#include "pch.h"
#include "ChernoEngine/Core.h"
#include "ChernoEngine/Events/Event.h"

namespace ChernoEngine
{

  struct CHERNOENGINE_API WindowProps
  {
    WindowProps() : 
        name("DEFAULT"), width(600), height(600), xPos(40), yPos(40) {}

    std::string name;
    int width;
    int height;
    int xPos;
    int yPos;
  };

  class CHERNOENGINE_API Window
  {
  public:
    virtual ~Window() {}

    virtual void onUpdate() = 0;
    virtual void setEventCallback(std::function<void(Event&)> event) = 0;
    virtual void shutdown() = 0;
    virtual void setVSync(int interval) const = 0;
    virtual int getVSync() const = 0;

    virtual int getWidth() const { return width; }
    virtual int getHeight() const { return height; }
    virtual int getXPos() const { return xPos; }
    virtual int getYPos() const { return yPos; }
    virtual std::string getName() { return name; }

    static Window* create(const WindowProps& windowProps);

  protected:
    std::string name;
    int width;
    int height;
    int xPos;
    int yPos;
  };

}


#endif
