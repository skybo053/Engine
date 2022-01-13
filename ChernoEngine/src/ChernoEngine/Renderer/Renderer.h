#ifndef RENDERER_H
#define RENDERER_H

#include "ChernoEngine/Renderer/RenderCommand.h"

namespace ChernoEngine
{
  
  class Renderer
  {
  public:

    Renderer();
    ~Renderer();

    static void beginScene();
    static void endScene();

    static void submit(const std::shared_ptr<VertexArray>& pVertexArray);

  private:
  };

}

#endif
