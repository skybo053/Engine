#include "Pch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace ChernoEngine
{

  RendererAPI* RenderCommand::rendererApi = new OpenGLRendererAPI();


  void RenderCommand::drawIndexed(const std::shared_ptr<VertexArray>& pVertexArray)
  {
    rendererApi->drawIndexed(pVertexArray);
  }

  void RenderCommand::clear()
  {
    rendererApi->clear();
  }

  void RenderCommand::setClearColor(const glm::vec4& pColor)
  {
    rendererApi->setClearColor(pColor);
  }


}