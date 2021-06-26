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
    virtual bool isMouseButtonPressedImpl(int pMouseButton) const override;
    virtual std::pair<int, int> getMousePositionImpl() const override;

  private:
  };
}


#endif

