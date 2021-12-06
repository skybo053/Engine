#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H

#include "ChernoEngine/Renderer/Buffer.h"

namespace ChernoEngine
{

  class OpenGLVertexBuffer : public VertexBuffer
  {
  public:
    OpenGLVertexBuffer(float* pVertices, uint32_t pSize);

    virtual void bind() const override;
    virtual void unbind() const override;

    virtual ~OpenGLVertexBuffer();

  private:
    uint32_t rendererId;
  };

  class OpenGLIndexBuffer : public IndexBuffer
  {
  public:
    OpenGLIndexBuffer(uint32_t* pIndices, uint32_t pSize);

    virtual void bind() const override;
    virtual void unbind() const override;
    virtual uint32_t getCount() const override;

    virtual ~OpenGLIndexBuffer();

  private:
    uint32_t rendererId = 0;
    uint32_t count;
  };

}

#endif
