#include "Pch.h"
#include "ImGuiLayer.h"

#include "imgui/imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl.h"

#include "ChernoEngine/Application.h"
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
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    //Getting native window and OpenGL context from Application singleton
    const Application& vApplication  = Application::getApplicationRef();
    SDL_Window*        vSdlWindow    = static_cast<SDL_Window*>(vApplication.getWindow().getNativeWindow());
    SDL_GLContext*     vSdlGLContext = static_cast<SDL_GLContext*>(vApplication.getWindow().getNativeGLContext());

    ImGui_ImplSDL2_InitForOpenGL(vSdlWindow, vSdlGLContext);
    ImGui_ImplOpenGL3_Init("#version 410");
  }
  
  
  void ImGuiLayer::onDetach()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
  }


  void ImGuiLayer::onImGuiRender()
  {
    static bool show = true;
    ImGui::ShowDemoWindow(&show);
  }


  void ImGuiLayer::begin()
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
  }


  void ImGuiLayer::end()
  {
    ImGuiIO&           vIo          = ImGui::GetIO();
    const Application& vApplication = Application::getApplicationRef();

    vIo.DisplaySize = ImVec2(vApplication.getWindow().getWidth(), vApplication.getWindow().getHeight());

    //Rendering
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


  ImGuiLayer::~ImGuiLayer()
  {

  }

}// end ChernoEngine namespace