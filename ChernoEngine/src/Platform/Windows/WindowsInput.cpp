#include "Pch.h"
#include "WindowsInput.h"

#include <sdl/SDL.h>


namespace ChernoEngine
{

  bool WindowsInput::isKeyPressedImpl(int pScancode) const
  {
    const uint8_t* vKeyStates = SDL_GetKeyboardState(NULL);

    return vKeyStates[pScancode];
  }


  bool WindowsInput::isMouseButtonPressedImpl(int pMouseButton) const
  {
    uint32_t vMouseStates = SDL_GetMouseState(NULL, NULL);

    return vMouseStates & SDL_BUTTON(pMouseButton);
  }


  std::pair<int, int> WindowsInput::getMousePositionImpl() const
  {
    int vXPos = 0;
    int vYPos = 0;

    SDL_GetMouseState(&vXPos, &vYPos);

    return std::make_pair(vXPos, vYPos);
  }

}