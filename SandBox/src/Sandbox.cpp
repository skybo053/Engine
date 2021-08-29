#include <ChernoEngine.h>

// ====================================
//  Test layer to add to engine layers
// =====================================
class TestLayer : public ChernoEngine::Layer
{
public:
  TestLayer(std::string name) : Layer(name) {}

  void onAttach() override
  {

  }

  void onUpdate() override
  {

  }

  void onEvent(ChernoEngine::Event& pEvent) override
  {
    if(pEvent.getEventType() == ChernoEngine::EventType::KEYEVENT)
    {
      ChernoEngine::KeyEvent& vKeyEvent = static_cast<ChernoEngine::KeyEvent&>(pEvent);

      if(vKeyEvent.getKeyCode()   == ChernoEngine::CE_KEYCODE_TAB &&
         vKeyEvent.getKeyAction() == ChernoEngine::CE_KEY_PRESSED)
      {
        CLIENTLOGGER_INFO("TAB was pressed with keycode: {}", vKeyEvent.getKeyCode());
      }
    }

    pEvent.setWasHandled(true);
  }

private:
};


// =======================================
//          Engine application
// =======================================
class Sandbox : public ChernoEngine::Application
{
public:
  Sandbox()
  {
    int w = getWindowWidth();
    int h = getWindowHeight();

    pushOverlay(new ChernoEngine::ImGuiLayer("ImGuiLayer", w, h));

    pushLayer(new TestLayer("TestLayer"));
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