#ifndef BUFFERLAYOUT_H
#define BUFFERLAYOUT_H

#include "glad/glad.h"

namespace ChernoEngine
{
  enum ShaderDataType
  {
    NONE,
    FLOAT,
    FLOAT_2,
    FLOAT_3,
    FLOAT_4, 
    MAT_3,
    MAT_4, 
    INT,
    INT_2,
    INT_3,
    INT_4,
    BOOL
  };


  static uint32_t getShaderDataTypeSize(ShaderDataType pShaderDataType)
  {
    switch(pShaderDataType)
    {                                    
      case NONE:    return 0;            
      case FLOAT:   return 4;            
      case FLOAT_2: return 4 * 2;        
      case FLOAT_3: return 4 * 3;        
      case FLOAT_4: return 4 * 4;        
      case MAT_3:   return 4 * 3 * 3;    
      case MAT_4:   return 4 * 4 * 4;    
      case INT:     return 4;            
      case INT_2:   return 4 * 2;        
      case INT_3:   return 4 * 3;        
      case INT_4:   return 4 * 4;        
      case BOOL:    return 1;            
      default:      return 0;            
    }                                    
  }

  static uint32_t getComponentCount(ShaderDataType pShaderDataType)
  {
    switch(pShaderDataType)
    {
      case NONE:    return 0;
      case FLOAT:
      case INT:
      case BOOL:    return 1;
      case FLOAT_2:
      case INT_2:   return 2;
      case FLOAT_3:
      case INT_3:   return 3;
      case FLOAT_4:
      case INT_4:   return 4;
      case MAT_3:   return 3 * 3;
      case MAT_4:   return 4 * 4;
      default:      return 0;
    }
  }

  static GLenum convertToOpenGLType(ShaderDataType pShaderDataType)
  {
    switch(pShaderDataType)
    {
    case MAT_3:
    case MAT_4:
    case FLOAT:
    case FLOAT_2:
    case FLOAT_3:
    case FLOAT_4: return GL_FLOAT;
    case INT:
    case INT_2:
    case INT_3:
    case INT_4: return GL_INT;
    case BOOL: return GL_BOOL;
    default: 0;
    }
  }

  struct BufferElement
  {
    BufferElement(ShaderDataType pShaderDataType, const std::string& pName, bool pNormalized = false)
      : name(pName), shaderDataType(pShaderDataType), componentCount(getComponentCount(pShaderDataType)), size(getShaderDataTypeSize(pShaderDataType)), offset(0), normalized(pNormalized) {}

    std::string    name;
    ShaderDataType shaderDataType;
    uint32_t       componentCount;
    uint32_t       offset;
    uint32_t       size;
    bool           normalized;
  };


  class BufferLayout
  {
  public:
    BufferLayout() {}

    BufferLayout(const std::initializer_list<BufferElement>& bufferElementList) : bufferElements(bufferElementList) 
    {
      calculateOffsetAndStride();
    }

    uint32_t getStride() const
    {
      return stride;
    }

    std::vector<BufferElement>::const_iterator begin() const
    {
      return bufferElements.begin();
    }

    std::vector<BufferElement>::const_iterator end() const 
    {
      return bufferElements.end();
    }

    ~BufferLayout() {}

  private:
    //functions
    void calculateOffsetAndStride()
    {
      uint32_t vOffset = 0;

      stride = 0;

      for(BufferElement& vBufferElement : bufferElements)
      {
        vBufferElement.offset  = vOffset;
        vOffset               += vBufferElement.size;
        stride                += vBufferElement.size;
      }
    }

    //members
    std::vector<BufferElement> bufferElements;
    uint32_t stride;
  };

}

#endif


