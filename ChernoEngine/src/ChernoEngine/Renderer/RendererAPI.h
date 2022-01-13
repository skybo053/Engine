#ifndef RENDERERAPI_H
#define RENDERERAPI_H

#include "ChernoEngine/Renderer/VertexArray.h"

#include <glm/glm.hpp>


namespace ChernoEngine
{

  class RendererAPI
  {
  public:
    enum API_TYPE
    {
      NONE,
      OPENGL,
      DIRECTX
    };

    virtual void clear() const = 0;
    virtual void setClearColor(const glm::vec4& pColor) const = 0;
    virtual void drawIndexed(const std::shared_ptr<VertexArray>& pVertexArray) const = 0;

    static constexpr API_TYPE ACTIVE_API = OPENGL;
  private:
  };

}


#endif

