#ifndef SHADER_H
#define SHADER_H

namespace ChernoEngine
{

  class Shader
  {
  public:
    virtual void bind() const = 0;
    virtual void unbind() const = 0;

  protected:
    Shader(const std::string& pVertexShaderSrc, const std::string& pFragmentShaderSrc) 
      : vertexShaderSource(pVertexShaderSrc), fragmentShaderSource(pFragmentShaderSrc) {}

    std::string vertexShaderSource;
    std::string fragmentShaderSource;
  };

}

#endif
