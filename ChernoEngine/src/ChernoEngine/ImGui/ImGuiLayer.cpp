#include "Pch.h"
#include "ImGuiLayer.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

#include <sdl/SDL.h>


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

    float currentTimeMillis = SDL_GetTicks();
    io.DeltaTime = time > 0.0F ? (currentTimeMillis - time) / 1000.0 : (1.0f / 60.0f);
    time = currentTimeMillis;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool vShow = true;
    ImGui::ShowDemoWindow(&vShow);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }


  void ImGuiLayer::onEvent(Event& pEvent)
  {

  }


  int ImGuiLayer::getDisplayWidth() const
  {
    return displayWidth;
  }


  int ImGuiLayer::getDisplayHeight() const
  {
    return displayHeight;
  }


  ImGuiLayer::~ImGuiLayer()
  {

  }

}// end ChernoEngine namespace