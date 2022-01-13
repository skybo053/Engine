#include "Pch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>


namespace ChernoEngine
{
  
  void OpenGLRendererAPI::clear() const
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }
  
  
  void OpenGLRendererAPI::setClearColor(const glm::vec4& pColor) const
  {
    glClearColor(pColor.r, pColor.g, pColor.b, pColor.a);
  }


  void OpenGLRendererAPI::drawIndexed(const std::shared_ptr<VertexArray>& pVertexArray) const
  {
    glDrawElements(GL_TRIANGLES, pVertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, NULL);
  };

}

