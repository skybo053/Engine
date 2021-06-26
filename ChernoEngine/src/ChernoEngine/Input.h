#ifndef INPUT_H
#define INPUT_H

#include "Core.h"


namespace ChernoEngine
{

  class CHERNOENGINE_API Input
  {
  public:
    static bool isKeyPressed(int pKeycode);
    static bool isMouseButtonPressed(int pMouseButton);

  protected:
    virtual bool isKeyPressedImpl(int pScancode) const = 0;
    virtual bool isMouseButtonPressedImpl(int pMouseButton) const = 0;

  private:
    static Input* input;
  };

}

#endif
