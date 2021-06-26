#include "Pch.h"
#include "Input.h"

#ifdef CE_PLATFORM_WINDOWS
  #include "Platform/Windows/WindowsInput.h"
#endif


namespace ChernoEngine
{

#ifdef CE_PLATFORM_WINDOWS
  Input* Input::input = new WindowsInput();
#endif

  bool Input::isKeyPressed(int pKeycode) 
  { 
    return input->isKeyPressedImpl(pKeycode); 
  }

  bool Input::isMouseButtonPressed(int pMouseButton)
  {
    return input->isMouseButtonPressedImpl(pMouseButton);
  }

  std::pair<int, int> Input::getMousePosition()
  {
    return input->getMousePositionImpl();
  }

}