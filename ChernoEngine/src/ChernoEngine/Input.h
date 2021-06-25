#ifndef INPUT_H
#define INPUT_H

#include "Core.h"


namespace ChernoEngine
{
  class CHERNOENGINE_API Input
  {
  public:
    static bool isKeyPressed(int pKeycode) {return input->isKeyPressedImpl(pKeycode);}
  protected:
    virtual bool isKeyPressedImpl(int pScancode) const = 0;
  private:
    static Input* input;
  };
}

#endif
