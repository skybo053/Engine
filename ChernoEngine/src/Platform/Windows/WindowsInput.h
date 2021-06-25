#ifndef WINDOWSINPUT_H
#define WINDOWSINPUT_H

#include "ChernoEngine/Core.h"
#include "ChernoEngine/Input.h"


namespace ChernoEngine
{
  class CHERNOENGINE_API WindowsInput : public Input
  {
  public:
    virtual bool isKeyPressedImpl(int pScancode) const override;
  private:
  };
}


#endif

