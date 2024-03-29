#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "ChernoEngine/Renderer/Buffer.h"

namespace ChernoEngine
{


  class VertexArray
  {
  public:

    virtual ~VertexArray() {}

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& pVertexBuffer) = 0;
    virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& pIndexBuffer) = 0;

    virtual const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffers() const = 0;
    virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const = 0;

    static VertexArray* create();

  private:
  
  };


}

#endif