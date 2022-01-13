#include "Pch.h"
#include "Buffer.h"
#include "ChernoEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace ChernoEngine
{

  VertexBuffer* VertexBuffer::create(float* pVertices, uint32_t pSize)
  {
    switch(RendererAPI::ACTIVE_API)
    {
      case RendererAPI::OPENGL:
      {
        return new OpenGLVertexBuffer(pVertices, pSize);
      }
      case RendererAPI::NONE:
      case RendererAPI::DIRECTX:
      default:

        CORELOGGER_ERROR("No Renderer API defined for API: {}", RendererAPI::ACTIVE_API);

        return nullptr;
    }
  }


  IndexBuffer* IndexBuffer::create(uint32_t* pIndices, uint32_t pCount)
  {
    switch(RendererAPI::ACTIVE_API)
    {
    case RendererAPI::OPENGL:
    {
      return new OpenGLIndexBuffer(pIndices, pCount);
    }
    case RendererAPI::NONE:
    case RendererAPI::DIRECTX:
    default:

      CORELOGGER_ERROR("No Renderer API defined for API: {}", RendererAPI::ACTIVE_API);

      return nullptr;
    }
  }

}