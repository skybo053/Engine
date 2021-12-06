#ifndef RENDERER_H
#define RENDERER_H

namespace ChernoEngine
{

  enum class RendererAPI
  {
    NONE,
    OPEN_GL,
    DIRECT_X
  };

  class Renderer
  {
  public:

    Renderer();
    ~Renderer();

    static constexpr RendererAPI rendererApi = RendererAPI::OPEN_GL;
  private:
  };

}

#endif
