#include <ChernoEngine.h>


class Sandbox : public ChernoEngine::Application
{
public:
  Sandbox()
  {
    int w = getWindowWidth();
    int h = getWindowHeight();

    pushOverlay(new ChernoEngine::ImGuiLayer("ImGuiLayer", w, h));
  }

  ~Sandbox()
  {

  }
private:
};


ChernoEngine::Application* ChernoEngine::createApplication()
{
  return new Sandbox();
}