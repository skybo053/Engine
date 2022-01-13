#include "Pch.h"
#include "Renderer.h"

namespace ChernoEngine
{

  Renderer::Renderer()
  {

  }


  Renderer::~Renderer()
  {

  }

  void Renderer::beginScene()
  {
  }

  void Renderer::endScene()
  {
  }

  void Renderer::submit(const std::shared_ptr<VertexArray>& pVertexArray)
  {
    pVertexArray->bind();
    RenderCommand::drawIndexed(pVertexArray);
  }


}