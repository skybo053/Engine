#ifndef OPENGLVERTEXARRAY_H
#define OPENGLVERTEXARRAY_H

#include "ChernoEngine/Renderer/Buffer.h"
#include "ChernoEngine/Renderer/VertexArray.h"


namespace ChernoEngine
{

  class OpenGLVertexArray : public VertexArray
  {
  public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    virtual void bind() const override;
    virtual void unbind() const override;

    virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& pVertexBuffer) override;
    virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& pIndexBuffer) override;

    virtual const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffers() const override;
    virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const override;

  private:
    std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;
    std::shared_ptr<IndexBuffer>               indexBuffer;
    GLuint rendererId;
  };

}

#endif



