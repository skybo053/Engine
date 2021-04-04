#ifdef CE_PLATFORM_WINDOWS
  #ifndef WINDOWSWINDOW_H
  #define WINDOWSWINDOW_H

#include "ChernoEngine/Core.h"
#include "ChernoEngine/Events/Event.h"
#include "ChernoEngine/Events/MouseClickEvent.h"
#include "ChernoEngine/Events/MouseMotionEvent.h"
#include "Window.h"

#include <sdl/SDL.h>

namespace ChernoEngine
{

  class CHERNOENGINE_API WindowsWindow : public Window
  {
    friend class Window;

  public:
    ~WindowsWindow();

    void onUpdate() override;
    void setEventCallback(std::function<void(Event&)> pEvent) override;
    void setVSync(int pInterval) const override;
    int getVSync() const override;

  private:
    //functions
    WindowsWindow(const WindowProps& pWindowProps);
    void shutdown();
    void handleWindowEvent(const SDL_WindowEvent& pEvent) const;

    MouseClickEvent::MouseButton getMouseButtonClicked(const uint8_t pButtonClicked) const; 
    std::set<MouseClickEvent::MouseButton> setMouseButtonsDown(uint32_t pButtonsDown) const;

    //members
    SDL_Window* window = nullptr;

    SDL_GLContext               glContext;
    std::function<void(Event&)> eventCallback;
  };

}


  #endif
#endif