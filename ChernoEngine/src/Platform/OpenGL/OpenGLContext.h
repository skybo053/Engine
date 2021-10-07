#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include "ChernoEngine/Renderer/GraphicsContext.h"
#include <sdl/SDL.h>

namespace ChernoEngine
{

  class OpenGLContext : public GraphicsContext
  {
  public:
    OpenGLContext(SDL_Window* pWindow);

    virtual void init() override;
    virtual void swapBuffers() override;

    void* getNativeGLContext();
  private:
    SDL_Window*   window;
    SDL_GLContext glContext;
  };

}

#endif
