#ifndef OPENGLSHADER_H
#define OPENGLSHADER_H

#include "ChernoEngine/Renderer/Shader.h"
#include <string>

namespace ChernoEngine
{

  class OpenGLShader : public Shader
  {
  public:
    OpenGLShader(const std::string& pVertexShaderSource, const std::string& pFragmentShaderSource);
    ~OpenGLShader();

    virtual void bind() const;
    virtual void unbind() const;
  private:
    uint32_t rendererId;
  };


}

#endif
