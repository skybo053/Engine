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

}