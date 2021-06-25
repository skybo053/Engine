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
}