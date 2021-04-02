#include "Pch.h"

#include "WindowsWindow.h"

#include "ChernoEngine/Log.h"
#include "ChernoEngine/Events/WindowResizedEvent.h"
#include "ChernoEngine/Events/WindowClosedEvent.h"
#include "ChernoEngine/Events/KeyEvent.h"
#include "ChernoEngine/Events/MouseWheelEvent.h"
#include "ChernoEngine/Events/MouseMotionEvent.h"


namespace ChernoEngine
{
  Window* Window::create(const WindowProps& pWindowProps)
  {
    if(SDL_WasInit(SDL_INIT_VIDEO) != 0)
    {
      CORELOGGER_INFO("Initializing SDL Video Subsystem...");

      if(SDL_Init(SDL_INIT_VIDEO) != 0)
      {
        CORELOGGER_ERROR("Error loading SDL video Subsystem. Failed with message: {0}. ", SDL_GetError());
        //exit engine startup ?
      }
    }

    return new WindowsWindow(pWindowProps);
  }


  WindowsWindow::WindowsWindow(const WindowProps& pWindowProps)
  {
    name   = pWindowProps.name;
    width  = pWindowProps.width;
    height = pWindowProps.height;
    xPos   = pWindowProps.xPos;
    yPos   = pWindowProps.yPos;

    CORELOGGER_INFO("Creating WindowsWindow {0} at position ({1}, {2})", name, xPos, yPos);

    window = SDL_CreateWindow(name.c_str(), xPos, yPos, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if(!window)
    {
      CORELOGGER_ERROR("Unable to create WindowsWindow. Error: {0}", SDL_GetError());
    }

    //set up openGL stuff
    glContext = SDL_GL_CreateContext(window);
    setVSync(1);
  }


  void WindowsWindow::onUpdate()
  {
    SDL_Event vSDLEvent;

    while(SDL_PollEvent(&vSDLEvent))
    {
      switch(vSDLEvent.type)
      {
        case SDL_WINDOWEVENT:
        {
          handleWindowEvent(vSDLEvent.window);

          break;
        }
        case SDL_KEYDOWN:
        {
          eventCallback(
            KeyEvent(
              vSDLEvent.key.keysym.sym, 
              KeyEvent::KeyAction::PRESSED, 
              (vSDLEvent.key.repeat == 0 ? false : true)));

          break;
        }
        case SDL_KEYUP:
        {
          eventCallback(
            KeyEvent(
              vSDLEvent.key.keysym.sym,
              KeyEvent::KeyAction::RELEASED,
              false));

          break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
          SDL_MouseButtonEvent vMouseButtonEvent = vSDLEvent.button;

          eventCallback(
            MouseClickEvent(
              vMouseButtonEvent.x, 
              vMouseButtonEvent.y, 
              getMouseButtonClicked(vMouseButtonEvent.button),
              MouseClickEvent::MouseAction::RELEASED));

          break;
        }
        case SDL_MOUSEBUTTONUP:
        {
          SDL_MouseButtonEvent vMouseButtonEvent = vSDLEvent.button;

          eventCallback(
            MouseClickEvent(
              vMouseButtonEvent.x,
              vMouseButtonEvent.y,
              getMouseButtonClicked(vMouseButtonEvent.button),
              MouseClickEvent::MouseAction::RELEASED));

          break;
        }
        case SDL_MOUSEWHEEL:
        {
          SDL_MouseWheelEvent vMouseWheelEvent = vSDLEvent.wheel;

          eventCallback(
          MouseWheelEvent(
            vMouseWheelEvent.x, 
            vMouseWheelEvent.y, 
            vMouseWheelEvent.direction == SDL_MOUSEWHEEL_NORMAL ? MouseWheelEvent::Direction::NORMAL : MouseWheelEvent::Direction::FLIPPED));

          break;
        }
        case SDL_MOUSEMOTION:
        {
          SDL_MouseMotionEvent vMouseMotionEvent = vSDLEvent.motion;
          int                  vButtonState      = vMouseMotionEvent.state;

          eventCallback(
            MouseMotionEvent(
              vMouseMotionEvent.x,
              vMouseMotionEvent.y,
              vButtonState == 0 ? MouseClickEvent::MouseButton::NONE :  getMouseButtonClicked(SDL_BUTTON(vButtonState))));

          break;
        }
      }
    }//end while PollEvents
   
    SDL_GL_SwapWindow(window);
  }


  void WindowsWindow::handleWindowEvent(const SDL_WindowEvent& pWindowEvent) const
  {
    switch(pWindowEvent.event)
    {
      case SDL_WINDOWEVENT_RESIZED:
      {
        eventCallback(WindowResizedEvent(pWindowEvent.data1, pWindowEvent.data2));
        break;
      }
      case SDL_WINDOWEVENT_CLOSE:
      {
        eventCallback(WindowClosedEvent());
        break;
      }
    }
  }


  MouseClickEvent::MouseButton WindowsWindow::getMouseButtonClicked(uint8_t pButton) const
  {
    MouseClickEvent::MouseButton vButtonClicked;

    switch(pButton)
    {
      case SDL_BUTTON_LEFT:
      {
        vButtonClicked = MouseClickEvent::MouseButton::L_BUTTON;
        break;
      }
      case SDL_BUTTON_MIDDLE:
      {
        vButtonClicked = MouseClickEvent::MouseButton::M_BUTTON;
        break;
      }
      case SDL_BUTTON_RIGHT:
      {
        vButtonClicked = MouseClickEvent::MouseButton::R_BUTTON;
        break;
      }
      default:
      {
        vButtonClicked = MouseClickEvent::MouseButton::NONE;
      } 
    }

    return vButtonClicked;
  }

  //int WindowsWindow::getMouseMotionButtonState(int pButtonState) const
  //{
  //  switch(pButtonState)
  //  {
  //    case SDL_BUTTO
  //  }
  //}


  void WindowsWindow::shutdown()
  {
    CORELOGGER_INFO("WindowsWindow shutting down...");

    if(window != nullptr)
    {
      SDL_DestroyWindow(window);
    }
  }


  void WindowsWindow::setEventCallback(std::function<void(Event&)> pEvent)
  {
    eventCallback = pEvent;
  }


  void WindowsWindow::setVSync(int pInterval) const
  {
    if(pInterval == 1)
    {
      SDL_GL_SetSwapInterval(1);
    }
    else
    {
      SDL_GL_SetSwapInterval(0);
    }
  }


  int WindowsWindow::getVSync() const
  {
    return SDL_GL_GetSwapInterval();
  }


  WindowsWindow::~WindowsWindow()
  {
    shutdown();
  }

}