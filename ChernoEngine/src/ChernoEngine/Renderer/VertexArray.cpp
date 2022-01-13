#include "Pch.h"

#include "ChernoEngine/Renderer/VertexArray.h"
#include "ChernoEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"


namespace ChernoEngine
{
  
  VertexArray* VertexArray::create()
  {
    switch(RendererAPI::ACTIVE_API)
    {
      case RendererAPI::OPENGL:
      {
        return new OpenGLVertexArray();
      }
      case RendererAPI::NONE:
      case RendererAPI::DIRECTX:
      default:
      {
        CORELOGGER_ERROR("No Renderer API defined for API: {}", RendererAPI::ACTIVE_API);

        return nullptr;
      }
    }
  }


}