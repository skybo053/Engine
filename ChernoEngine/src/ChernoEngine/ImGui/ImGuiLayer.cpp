#include "Pch.h"
#include "ImGuiLayer.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

#include <sdl/SDL.h>
#include "glad/glad.h"


namespace ChernoEngine
{
  ImGuiLayer::ImGuiLayer(const std::string& pLayerName, int displayWidth, int displayHeight) 
    : displayWidth(displayWidth), displayHeight(displayHeight), Layer(pLayerName)
  {

  }
  
  
  void ImGuiLayer::onAttach()
  {
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO();

    io.DisplaySize  = ImVec2(displayWidth, displayHeight);
    io.BackendFlags = io.BackendFlags | ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags = io.BackendFlags | ImGuiBackendFlags_HasSetMousePos;

    //Temporary - Will use ChernoEngine keycodes
    io.KeyMap[ImGuiKey_Tab] = SDL_SCANCODE_TAB;
    io.KeyMap[ImGuiKey_LeftArrow] = SDL_SCANCODE_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = SDL_SCANCODE_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = SDL_SCANCODE_UP;
    io.KeyMap[ImGuiKey_DownArrow] = SDL_SCANCODE_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = SDL_SCANCODE_PAGEUP;
    io.KeyMap[ImGuiKey_PageDown] = SDL_SCANCODE_PAGEDOWN;
    io.KeyMap[ImGuiKey_Home] = SDL_SCANCODE_HOME;
    io.KeyMap[ImGuiKey_End] = SDL_SCANCODE_END;
    io.KeyMap[ImGuiKey_Insert] = SDL_SCANCODE_INSERT;
    io.KeyMap[ImGuiKey_Delete] = SDL_SCANCODE_DELETE;
    io.KeyMap[ImGuiKey_Backspace] = SDL_SCANCODE_BACKSPACE;
    io.KeyMap[ImGuiKey_Space] = SDL_SCANCODE_SPACE;
    io.KeyMap[ImGuiKey_Enter] = SDL_SCANCODE_RETURN;
    io.KeyMap[ImGuiKey_Escape] = SDL_SCANCODE_ESCAPE;
    io.KeyMap[ImGuiKey_KeyPadEnter] = SDL_SCANCODE_KP_ENTER;
    io.KeyMap[ImGuiKey_A] = SDL_SCANCODE_A;
    io.KeyMap[ImGuiKey_C] = SDL_SCANCODE_C;
    io.KeyMap[ImGuiKey_V] = SDL_SCANCODE_V;
    io.KeyMap[ImGuiKey_X] = SDL_SCANCODE_X;
    io.KeyMap[ImGuiKey_Y] = SDL_SCANCODE_Y;
    io.KeyMap[ImGuiKey_Z] = SDL_SCANCODE_Z;

    ImGui_ImplOpenGL3_Init("#version 410");
  }
  
  
  void ImGuiLayer::onDetach()
  {

  }


  void ImGuiLayer::onUpdate()
  {
    ImGuiIO& io = ImGui::GetIO();

    uint64_t frequency   = SDL_GetPerformanceFrequency();
    uint64_t currentTime = SDL_GetPerformanceCounter();

    io.DeltaTime = time > 0 ? (float)((double)(currentTime - time) / frequency) : (float)(1.0f / 60.0f);
    time = currentTime;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool vShow = true;
    ImGui::ShowDemoWindow(&vShow);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }


  int ImGuiLayer::getDisplayWidth() const
  {
    return displayWidth;
  }


  int ImGuiLayer::getDisplayHeight() const
  {
    return displayHeight;
  }


  void ImGuiLayer::onEvent(Event& pEvent)
  {
    switch(pEvent.getEventType())
    {
      case EventType::MOUSEMOTIONEVENT:
      {
        onMouseMotionEvent(static_cast<MouseMotionEvent&>(pEvent));
        break;
      }
      case EventType::MOUSECLICKEVENT:
      {
        onMouseClickEvent(static_cast<MouseClickEvent&>(pEvent));
        break;
      }
      case EventType::KEYEVENT:
      {
        onKeyEvent(static_cast<KeyEvent&>(pEvent));
        break;
      }
      case EventType::TEXTINPUTEVENT:
      {
        onTextInputEvent(static_cast<TextInputEvent&>(pEvent));
        break;
      }
      case EventType::MOUSEWHEELEVENT:
      {
        onMouseWheelEvent(static_cast<MouseWheelEvent&>(pEvent));
        break;
      }
      case EventType::WINDOWCLOSEDEVENT:
      {
        onWindowClosedEvent(static_cast<WindowClosedEvent&>(pEvent));
        break;
      }
      case EventType::WINDOWRESIZEDEVENT:
      {
        onWindowResizedEvent(static_cast<WindowResizedEvent&>(pEvent));
        break;
      }
      default:
      {
        CORELOGGER_ERROR("ImGuiLayer::onEvent - Unrecognized event: {0}", pEvent);
      }
    }
  }


  bool ImGuiLayer::onKeyEvent(KeyEvent& pKeyEvent)
  {
    ImGuiIO&            vIO        = ImGui::GetIO();
    KeyEvent::KeyAction vKeyAction = pKeyEvent.getKeyAction();

    if(vKeyAction == KeyEvent::KeyAction::PRESSED)
    {
      vIO.KeysDown[pKeyEvent.getKeyCode()] = true;

      vIO.KeyCtrl  = vIO.KeysDown[SDL_SCANCODE_LCTRL]  || vIO.KeysDown[SDL_SCANCODE_RCTRL];
      vIO.KeyShift = vIO.KeysDown[SDL_SCANCODE_LSHIFT] || vIO.KeysDown[SDL_SCANCODE_RSHIFT];
      vIO.KeyAlt   = vIO.KeysDown[SDL_SCANCODE_LALT]   || vIO.KeysDown[SDL_SCANCODE_RALT];
      vIO.KeySuper = vIO.KeysDown[SDL_SCANCODE_LGUI]   || vIO.KeysDown[SDL_SCANCODE_RGUI];
    }
    else if(vKeyAction == KeyEvent::KeyAction::RELEASED)
    {
      vIO.KeysDown[pKeyEvent.getKeyCode()] = false;

      vIO.KeyCtrl  = vIO.KeysDown[SDL_SCANCODE_LCTRL]  || vIO.KeysDown[SDL_SCANCODE_RCTRL];
      vIO.KeyShift = vIO.KeysDown[SDL_SCANCODE_LSHIFT] || vIO.KeysDown[SDL_SCANCODE_RSHIFT];
      vIO.KeyAlt   = vIO.KeysDown[SDL_SCANCODE_LALT]   || vIO.KeysDown[SDL_SCANCODE_RALT];
      vIO.KeySuper = vIO.KeysDown[SDL_SCANCODE_LGUI]   || vIO.KeysDown[SDL_SCANCODE_RGUI];
    }
    else
    {
      CORELOGGER_ERROR("ImGuiLayer::onKeyEvent - Unrecognized KeyAction for KeyEvent: {0}", pKeyEvent);
    }

    return false;
  }


  bool ImGuiLayer::onMouseClickEvent(MouseClickEvent& pMouseClickEvent)
  {
    ImGuiIO&                     vIo = ImGui::GetIO();
    MouseClickEvent::MouseAction vMouseAction = pMouseClickEvent.getMouseAction();
    MouseClickEvent::MouseButton vMouseButton = pMouseClickEvent.getMouseButton();

    if(vMouseAction == MouseClickEvent::MouseAction::PRESSED)
    {
      switch(vMouseButton)
      {
      case MouseClickEvent::MouseButton::L_BUTTON:
      {
        vIo.MouseDown[0] = true;
        break;
      }
      case MouseClickEvent::MouseButton::M_BUTTON:
      {
        vIo.MouseDown[2] = true;
        break;
      }
      case MouseClickEvent::MouseButton::R_BUTTON:
      {
        vIo.MouseDown[1] = true;
        break;
      }
      default:
      {
        CORELOGGER_WARN("ImGuiLayer::onMouseClickEvent - Unable to process MouseAction::PRESSED event: {0}", pMouseClickEvent);
      }
      }
    }
    else if(vMouseAction == MouseClickEvent::MouseAction::RELEASED)
    {
      switch(vMouseButton)
      {
        case MouseClickEvent::MouseButton::L_BUTTON:
        {
          vIo.MouseDown[0] = false;
          break;
        }
        case MouseClickEvent::MouseButton::M_BUTTON:
        {
          vIo.MouseDown[2] = false;
          break;
        }
        case MouseClickEvent::MouseButton::R_BUTTON:
        {
          vIo.MouseDown[1] = false;
          break;
        }
        default:
        {
          CORELOGGER_WARN("ImGuiLayer::onMouseClickEvent - Unable to process MouseAction::RELEASED event: {0}", pMouseClickEvent);
        }
      }
    }
    else
    {
      CLIENTLOGGER_ERROR("ImGuiLayer::onMouseClickEvent - Unknown MouseClickEvent received: {0}", pMouseClickEvent);
    }

    return false;
  }

  bool ImGuiLayer::onMouseMotionEvent(MouseMotionEvent& pMouseMotionEvent)
  {
    ImGuiIO& vIO = ImGui::GetIO();
    
    vIO.MousePos = ImVec2(pMouseMotionEvent.getXPosition(), pMouseMotionEvent.getYPosition());

    return false;
  }


  bool ImGuiLayer::onMouseWheelEvent(MouseWheelEvent& pMouseWheelEvent)
  {
    ImGuiIO& vIO = ImGui::GetIO();

    vIO.MouseWheelH = pMouseWheelEvent.getHorizontalScroll();
    vIO.MouseWheel  = pMouseWheelEvent.getVerticalScroll();

    return false;
  }


  bool ImGuiLayer::onWindowClosedEvent(WindowClosedEvent& pWindowClosedEvent)
  {
    return false;
  }


  bool ImGuiLayer::onWindowResizedEvent(WindowResizedEvent& pWindowResizedEvent)
  {
    ImGuiIO& vIO = ImGui::GetIO();

    vIO.DisplaySize = ImVec2(pWindowResizedEvent.getWidth(), pWindowResizedEvent.getHeight());
    vIO.DisplayFramebufferScale = ImVec2(1.0F, 1.0F);
    
    glViewport(0, 0, pWindowResizedEvent.getWidth(), pWindowResizedEvent.getHeight());

    return false;
  }


  bool ImGuiLayer::onTextInputEvent(TextInputEvent& pTextInputEvent)
  {
    ImGuiIO&    vIO        = ImGui::GetIO();
    const char* vInputText = pTextInputEvent.getText();

    vIO.AddInputCharactersUTF8(vInputText);

    return false;
  }


  ImGuiLayer::~ImGuiLayer()
  {

  }

}// end ChernoEngine namespace