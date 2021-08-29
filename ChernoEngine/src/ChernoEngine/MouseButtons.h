#ifndef MOUSEBUTTONS_H
#define MOUSEBUTTONS_H

namespace ChernoEngine
{
  enum CE_MouseButtonAction
  {
    CE_BUTTON_PRESSED,
    CE_BUTTON_RELEASED
  };

  enum CE_MouseButtonCode
  {
    CE_BUTTON_UNKNOWN,
    CE_BUTTON_LEFT = 1,
    CE_BUTTON_MIDDLE = 2,
    CE_BUTTON_RIGHT = 3,
    CE_BUTTON_X1 = 4,
    CE_BUTTON_X2 = 5,

    CE_BUTTON_NONE = 100 //for use with MouseMotionEvent if no mouse button is down
  };
}

#endif
