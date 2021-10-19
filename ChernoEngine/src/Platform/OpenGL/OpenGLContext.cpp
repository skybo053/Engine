#include "Pch.h"
#include "OpenGLContext.h"
#include "glad/glad.h"

namespace ChernoEngine
{

  OpenGLContext::OpenGLContext(SDL_Window* pWindow) : window(pWindow), glContext(SDL_GL_CreateContext(window))
  {

  }


  void OpenGLContext::init()
  {
    if(gladLoadGLLoader(SDL_GL_GetProcAddress) == NULL)
    {
      CORELOGGER_ERROR("Failed to initialize Glad system!");
    }
    else
    {
      CORELOGGER_INFO("Glad system initialized!");
    }
    
    CORELOGGER_INFO("GL Vendor: {0}", glGetString(GL_VENDOR));
    CORELOGGER_INFO("GL Renderer: {0}", glGetString(GL_RENDERER));
    CORELOGGER_INFO("GL Version: {0}", glGetString(GL_VERSION));
  }


  void OpenGLContext::swapBuffers()
  {
    SDL_GL_SwapWindow(window);
  }

  void * OpenGLContext::getNativeGLContext()
  {
    return glContext;
  }

}