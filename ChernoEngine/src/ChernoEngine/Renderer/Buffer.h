#ifndef BUFFER_H
#define BUFFER_H


namespace ChernoEngine
{

  class VertexBuffer
  {
  public:

    virtual ~VertexBuffer() {}

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    static VertexBuffer* create(float* pVertices, uint32_t pSize);

  private:
  };

  class IndexBuffer
  {
  public:
    virtual ~IndexBuffer() {}

    virtual void bind() const = 0;
    virtual void unbind() const = 0;
    virtual uint32_t getCount() const = 0;

    static IndexBuffer* create(uint32_t* pIndices, uint32_t pSize);
  private:
  };

}

#endif