#include "Pch.h"
#include "ImGuiLayer.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "ChernoEngine/MouseButtons.h"
#include "ChernoEngine/Keys.h"

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
    io.KeyMap[ImGuiKey_Tab] = CE_KEYCODE_TAB;
    io.KeyMap[ImGuiKey_LeftArrow] = CE_KEYCODE_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = CE_KEYCODE_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = CE_KEYCODE_UP;
    io.KeyMap[ImGuiKey_DownArrow] = CE_KEYCODE_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = CE_KEYCODE_PAGEUP;
    io.KeyMap[ImGuiKey_PageDown] = CE_KEYCODE_PAGEDOWN;
    io.KeyMap[ImGuiKey_Home] = CE_KEYCODE_HOME;
    io.KeyMap[ImGuiKey_End] = CE_KEYCODE_END;
    io.KeyMap[ImGuiKey_Insert] = CE_KEYCODE_INSERT;
    io.KeyMap[ImGuiKey_Delete] = CE_KEYCODE_DELETE;
    io.KeyMap[ImGuiKey_Backspace] = CE_KEYCODE_BACKSPACE;
    io.KeyMap[ImGuiKey_Space] = CE_KEYCODE_SPACE;
    io.KeyMap[ImGuiKey_Enter] = CE_KEYCODE_RETURN;
    io.KeyMap[ImGuiKey_Escape] = CE_KEYCODE_ESCAPE;
    io.KeyMap[ImGuiKey_KeyPadEnter] = CE_KEYCODE_KP_ENTER;
    io.KeyMap[ImGuiKey_A] = CE_KEYCODE_A;
    io.KeyMap[ImGuiKey_C] = CE_KEYCODE_C;
    io.KeyMap[ImGuiKey_V] = CE_KEYCODE_V;
    io.KeyMap[ImGuiKey_X] = CE_KEYCODE_X;
    io.KeyMap[ImGuiKey_Y] = CE_KEYCODE_Y;
    io.KeyMap[ImGuiKey_Z] = CE_KEYCODE_Z;

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
    ImGuiIO&     vIO        = ImGui::GetIO();
    CE_KeyAction vKeyAction = pKeyEvent.getKeyAction();

    if(vKeyAction == CE_KEY_PRESSED)
    {
      vIO.KeysDown[pKeyEvent.getKeyCode()] = true;

      vIO.KeyCtrl  = vIO.KeysDown[CE_KEYCODE_LCTRL]  || vIO.KeysDown[CE_KEYCODE_RCTRL];
      vIO.KeyShift = vIO.KeysDown[CE_KEYCODE_LSHIFT] || vIO.KeysDown[CE_KEYCODE_RSHIFT];
      vIO.KeyAlt   = vIO.KeysDown[CE_KEYCODE_LALT]   || vIO.KeysDown[CE_KEYCODE_RALT];
      vIO.KeySuper = vIO.KeysDown[CE_KEYCODE_LGUI]   || vIO.KeysDown[CE_KEYCODE_RGUI];
    }
    else if(vKeyAction == CE_KEY_RELEASED)
    {
      vIO.KeysDown[pKeyEvent.getKeyCode()] = false;

      vIO.KeyCtrl  = vIO.KeysDown[CE_KEYCODE_LCTRL]  || vIO.KeysDown[CE_KEYCODE_RCTRL];
      vIO.KeyShift = vIO.KeysDown[CE_KEYCODE_LSHIFT] || vIO.KeysDown[CE_KEYCODE_RSHIFT];
      vIO.KeyAlt   = vIO.KeysDown[CE_KEYCODE_LALT]   || vIO.KeysDown[CE_KEYCODE_RALT];
      vIO.KeySuper = vIO.KeysDown[CE_KEYCODE_LGUI]   || vIO.KeysDown[CE_KEYCODE_RGUI];
    }
    else
    {
      CORELOGGER_ERROR("ImGuiLayer::onKeyEvent - Unrecognized KeyAction for KeyEvent: {0}", pKeyEvent);
    }

    return false;
  }


  bool ImGuiLayer::onMouseClickEvent(MouseClickEvent& pMouseClickEvent)
  {
    ImGuiIO&             vIo          = ImGui::GetIO();
    CE_MouseButtonAction vMouseAction = pMouseClickEvent.getMouseAction();
    CE_MouseButtonCode   vMouseButton = pMouseClickEvent.getMouseButton();

    if(vMouseAction == CE_BUTTON_PRESSED)
    {
      switch(vMouseButton)
      {
      case CE_BUTTON_LEFT:
      {
        vIo.MouseDown[0] = true;
        break;
      }
      case CE_BUTTON_MIDDLE:
      {
        vIo.MouseDown[2] = true;
        break;
      }
      case CE_BUTTON_RIGHT:
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
    else if(vMouseAction == CE_BUTTON_RELEASED)
    {
      switch(vMouseButton)
      {
        case CE_BUTTON_LEFT:
        {
          vIo.MouseDown[0] = false;
          break;
        }
        case CE_BUTTON_MIDDLE:
        {
          vIo.MouseDown[2] = false;
          break;
        }
        case CE_BUTTON_RIGHT:
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