#include "Pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"

namespace ChernoEngine
{

  ChernoEngine::OpenGLShader::OpenGLShader(const std::string& pVertexShaderSource, const std::string& pFragmentShaderSource)
    : Shader(pVertexShaderSource, pFragmentShaderSource)
  {
    
    // Create an empty vertex shader handle
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Send the vertex shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    const GLchar *source = vertexShaderSource.c_str();
    glShaderSource(vertexShader, 1, &source, 0);

    // Compile the vertex shader
    glCompileShader(vertexShader);
    
    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character
      std::vector<GLchar> infoLog(maxLength);
      glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

      // We don't need the shader anymore.
      glDeleteShader(vertexShader);

      CORELOGGER_ERROR("Vertex shader compilation error!");
      CORELOGGER_ERROR("{0}", infoLog.data());
      CE_CORE_ASSERT(false, "Vertex shader compilation failure!");
      return;
    }

    // Create an empty fragment shader handle
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Send the fragment shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    source = fragmentShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &source, 0);

    // Compile the fragment shader
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character
      std::vector<GLchar> infoLog(maxLength);
      glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

      // We don't need the shader anymore.
      glDeleteShader(fragmentShader);
      // Either of them. Don't leak shaders.
      glDeleteShader(vertexShader);

      CORELOGGER_ERROR("Fragment shader compilation error!");
      CORELOGGER_ERROR("{0}", infoLog.data());
      CE_CORE_ASSERT(false, "Fragment shader compilation failure!");

      return;
    }

    // Vertex and fragment shaders are successfully compiled.
    // Now time to link them together into a program.
    // Get a program object.
    rendererId = glCreateProgram();
    GLuint program = rendererId;

    // Attach our shaders to our program
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    // Link our program
    glLinkProgram(program);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
    if(isLinked == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character
      std::vector<GLchar> infoLog(maxLength);
      glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

      // We don't need the program anymore.
      glDeleteProgram(program);
      // Don't leak shaders either.
      glDeleteShader(vertexShader);
      glDeleteShader(fragmentShader);

      CORELOGGER_ERROR("Shader link error!");
      CORELOGGER_ERROR("{0}", infoLog.data());
      CE_CORE_ASSERT(false, "Shader link failure!");
      return;
    }

    // Always detach shaders after a successful link.
    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);
  }


  void ChernoEngine::OpenGLShader::bind() const
  {
    glUseProgram(rendererId);
  }


  void ChernoEngine::OpenGLShader::unbind() const
  {
    glUseProgram(0);
  }


  ChernoEngine::OpenGLShader::~OpenGLShader()
  {
    glDeleteProgram(rendererId);
  }

}

