#ifndef RENDERCOMMAND_H
#define RENDERCOMMAND_H

#include "ChernoEngine/Renderer/RendererAPI.h"


namespace ChernoEngine
{

  class RenderCommand
  {
  public:
    static void clear();
    static void setClearColor(const glm::vec4& pColor);
    static void drawIndexed(const std::shared_ptr<VertexArray>& pVertexArray);
  private:
    static RendererAPI* rendererApi;
  };

}

#endif


