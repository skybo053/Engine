#ifndef OPENGLRENDERERAPI_H
#define OPENGLRENDERERAPI_H

#include "ChernoEngine/Renderer/RendererAPI.h"


namespace ChernoEngine
{

  class OpenGLRendererAPI : public RendererAPI
  {
  public:
    virtual void clear() const override;
    virtual void setClearColor(const glm::vec4& pColor) const override;
    virtual void drawIndexed(const std::shared_ptr<VertexArray>& pVertexArray) const override;
  private:
  };

}


#endif


