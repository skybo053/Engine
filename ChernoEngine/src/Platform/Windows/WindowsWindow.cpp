#include "Pch.h"

#include "Platform/Windows/WindowsWindow.h"

#include "ChernoEngine/Log.h"
#include "ChernoEngine/Events/WindowResizedEvent.h"
#include "ChernoEngine/Events/WindowClosedEvent.h"
#include "ChernoEngine/Events/KeyEvent.h"
#include "ChernoEngine/Events/MouseWheelEvent.h"
#include "ChernoEngine/Events/TextInputEvent.h"

#include "glad/glad.h"


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

    if(gladLoadGLLoader(SDL_GL_GetProcAddress) == NULL)
    {
      CORELOGGER_ERROR("Failed to initialize Glad system!");
    }
    else
    {
      CORELOGGER_INFO("Glad system initialized!");
    }

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
              vSDLEvent.key.keysym.scancode, 
              KeyEvent::KeyAction::PRESSED, 
              (vSDLEvent.key.repeat == 0 ? false : true)));

          break;
        }
        case SDL_KEYUP:
        {
          eventCallback(
            KeyEvent(
              vSDLEvent.key.keysym.scancode,
              KeyEvent::KeyAction::RELEASED,
              false));

          break;
        }
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        {
          SDL_MouseButtonEvent vMouseButtonEvent = vSDLEvent.button;
          uint8_t vButtonState                   = vMouseButtonEvent.state;

          eventCallback(
            MouseClickEvent(
              vMouseButtonEvent.x,
              vMouseButtonEvent.y,
              getMouseButtonClicked(vMouseButtonEvent.button),
              vButtonState == SDL_PRESSED ? MouseClickEvent::MouseAction::PRESSED : MouseClickEvent::MouseAction::RELEASED));

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
          uint32_t             vButtonsDown      = vMouseMotionEvent.state;

          eventCallback(
            MouseMotionEvent(
              vMouseMotionEvent.x,
              vMouseMotionEvent.y,
              vButtonsDown == 0 ? std::set<MouseClickEvent::MouseButton>() : setMouseButtonsDown(vButtonsDown)));

          break;
        }
        case SDL_TEXTINPUT:
        {
          SDL_TextInputEvent vTextInputEvent = vSDLEvent.text;

          eventCallback(TextInputEvent(vTextInputEvent.text));
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


  MouseClickEvent::MouseButton WindowsWindow::getMouseButtonClicked(const uint8_t pButtonClicked) const
  {
    if(pButtonClicked == SDL_BUTTON_RIGHT)
    {
      return MouseClickEvent::MouseButton::R_BUTTON;
    }

    if(pButtonClicked == SDL_BUTTON_MIDDLE)
    {
      return MouseClickEvent::MouseButton::M_BUTTON;
    }

    if(pButtonClicked == SDL_BUTTON_LEFT)
    {
      return MouseClickEvent::MouseButton::L_BUTTON;
    }

    return MouseClickEvent::MouseButton::NONE;
  }


  std::set<MouseClickEvent::MouseButton> WindowsWindow::setMouseButtonsDown(uint32_t pButtonsDown) const
  {
    std::set<MouseClickEvent::MouseButton> vMouseButtonsDown;

    if((pButtonsDown & SDL_BUTTON_RMASK) == SDL_BUTTON_RMASK)
    {
      vMouseButtonsDown.insert(MouseClickEvent::MouseButton::R_BUTTON);
    }

    if((pButtonsDown & SDL_BUTTON_MMASK) == SDL_BUTTON_MMASK)
    {
      vMouseButtonsDown.insert(MouseClickEvent::MouseButton::M_BUTTON);
    }

    if((pButtonsDown & SDL_BUTTON_LMASK) == SDL_BUTTON_LMASK)
    {
      vMouseButtonsDown.insert(MouseClickEvent::MouseButton::L_BUTTON);
    }

    return vMouseButtonsDown;
  }


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


  void* WindowsWindow::getNativeWindow() const
  {
    return window;
  }


  WindowsWindow::~WindowsWindow()
  {
    shutdown();
  }

}