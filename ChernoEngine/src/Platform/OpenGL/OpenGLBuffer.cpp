#include "Pch.h"
#include "OpenGLBuffer.h"
#include <glad/glad.h>

namespace ChernoEngine
{

  /*
   *  VertexBuffer
   */

  OpenGLVertexBuffer::OpenGLVertexBuffer(float* pVertices, uint32_t pSize)
  {
    glGenBuffers(1, &rendererId);
    glBindBuffer(GL_ARRAY_BUFFER, rendererId);
    glBufferData(GL_ARRAY_BUFFER, pSize, pVertices, GL_STATIC_DRAW);
  }

  void OpenGLVertexBuffer::bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, rendererId);
  }

  void OpenGLVertexBuffer::unbind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void OpenGLVertexBuffer::setBufferLayout(const BufferLayout& pBufferLayout)
  {
    bufferLayout = pBufferLayout;
  }

  const BufferLayout& OpenGLVertexBuffer::getBufferLayout() const
  {
    return bufferLayout;
  }

  OpenGLVertexBuffer::~OpenGLVertexBuffer()
  {
    glDeleteBuffers(1, &rendererId);
  }

  /*
   * IndexBuffer
   */

  OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* pIndices, uint32_t pCount) : count(pCount)
  {
    glGenBuffers(1, &rendererId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), pIndices, GL_STATIC_DRAW);
  }

  void OpenGLIndexBuffer::bind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
  }

  void OpenGLIndexBuffer::unbind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

  uint32_t OpenGLIndexBuffer::getCount() const
  {
    return count;
  }

  OpenGLIndexBuffer::~OpenGLIndexBuffer()
  {
    glDeleteBuffers(1, &rendererId);
  }

}
