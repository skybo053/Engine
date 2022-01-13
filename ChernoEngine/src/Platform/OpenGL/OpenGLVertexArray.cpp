#include "Pch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace ChernoEngine
{

  OpenGLVertexArray::OpenGLVertexArray()
  {
    glGenVertexArrays(1, &rendererId);
  }


  OpenGLVertexArray::~OpenGLVertexArray()
  {
    glDeleteVertexArrays(1, &rendererId);
  }


  void OpenGLVertexArray::bind() const
  {
    glBindVertexArray(rendererId);
  }


  void OpenGLVertexArray::unbind() const
  {
    glBindVertexArray(0);
  }

  
  void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& pVertexBuffer)
  {
    uint32_t     vVertexArrayIndex = 0;
    BufferLayout vBufferLayout     = pVertexBuffer->getBufferLayout();

    glBindVertexArray(rendererId);
    pVertexBuffer->bind();
    
    for(const BufferElement& vBufferElement : vBufferLayout)
    {
      glEnableVertexAttribArray(vVertexArrayIndex);

      glVertexAttribPointer(
        vVertexArrayIndex,
        vBufferElement.componentCount,
        convertToOpenGLType(vBufferElement.shaderDataType),
        vBufferElement.normalized ? GL_TRUE : GL_FALSE,
        vBufferLayout.getStride(),
        (const void*)vBufferElement.offset);

      ++vVertexArrayIndex;
    }

    vertexBuffers.push_back(pVertexBuffer);
  }


  void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& pIndexBuffer)
  {
    glBindVertexArray(rendererId);
    pIndexBuffer->bind();

    indexBuffer = pIndexBuffer;
  }

  const std::vector<std::shared_ptr<VertexBuffer>>& OpenGLVertexArray::getVertexBuffers() const
  {
    return vertexBuffers;
  }

  const std::shared_ptr<IndexBuffer>& OpenGLVertexArray::getIndexBuffer() const
  {
    return indexBuffer;
  }

}
