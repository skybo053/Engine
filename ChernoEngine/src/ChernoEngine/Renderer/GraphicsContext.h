#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace ChernoEngine
{

  class GraphicsContext
  {
  public:
    virtual void init() = 0;
    virtual void swapBuffers() = 0;
  private:
  };

}

#endif