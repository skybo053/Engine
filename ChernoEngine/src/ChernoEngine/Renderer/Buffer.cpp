#include "Pch.h"
#include "Buffer.h"
#include "ChernoEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace ChernoEngine
{

  VertexBuffer* VertexBuffer::create(float* pVertices, uint32_t pSize)
  {
    switch(Renderer::rendererApi)
    {
      case RendererAPI::OPEN_GL:
      {
        return new OpenGLVertexBuffer(pVertices, pSize);
      }
      case RendererAPI::NONE:
      case RendererAPI::DIRECT_X:
      default:

        CORELOGGER_ERROR("No Renderer API defined for API: {}", Renderer::rendererApi);

        return nullptr;
    }
  }


  IndexBuffer* IndexBuffer::create(uint32_t* pIndices, uint32_t pCount)
  {
    switch(Renderer::rendererApi)
    {
    case RendererAPI::OPEN_GL:
    {
      return new OpenGLIndexBuffer(pIndices, pCount);
    }
    case RendererAPI::NONE:
    case RendererAPI::DIRECT_X:
    default:

      CORELOGGER_ERROR("No Renderer API defined for API: {}", Renderer::rendererApi);

      return nullptr;
    }
  }

}