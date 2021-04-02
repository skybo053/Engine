#include <ChernoEngine.h>


class Sandbox : public ChernoEngine::Application
{
public:
  Sandbox()
  {

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