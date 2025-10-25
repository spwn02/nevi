#include "Shader.h"
#include <sstream>
#include <fstream>
#include <vector>

#include "Utils.h"

#include <glad/glad.h>

static std::string base_path("../../../app/assets/shaders/");

namespace Core {

  Shader::Shader(const char* filename)
  {
    std::string filepath = base_path + std::string(filename);
    std::ifstream stream(filepath.c_str());

    LOG_ASSERT(stream.is_open(), "Cannot open a file: {0}!", filepath.c_str());

    std::stringstream ss[2];

    enum ShaderType
    {
      NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    ShaderType type(ShaderType::NONE);

    while (getline(stream, line))
    {
      if (line.find("#shader") != std::string::npos)
      {
        if (line.find("vertex") != std::string::npos)
          type = ShaderType::VERTEX;
        else if (line.find("fragment") != std::string::npos)
          type = ShaderType::FRAGMENT;
      }
      else
      {
        if (type == ShaderType::NONE) continue;
        ss[(int)type] << line << '\n';
      }
    }

    createShader(ss[0].str().c_str(), ss[1].str().c_str());
  }

  Shader::Shader(const char* vertexPath, const char* fragmentPath)
  {
    std::string vPath = base_path + std::string(vertexPath);
    std::ifstream vStream(vPath.c_str());

    LOG_ASSERT(vStream.is_open(), "Cannot open a file: {0}", vPath);

    std::string fPath = base_path + std::string(fragmentPath);
    std::ifstream fStream(fPath.c_str());

    LOG_ASSERT(fStream.is_open(), "Cannot open a file: {0}", fPath);

    std::stringstream ss[2];
    std::string line;

    while (getline(vStream, line))
    {
      ss[0] << line << '\n';
    }

    line.clear();

    while (getline(fStream, line))
    {
      ss[1] << line << '\n';
    }

    createShader(ss[0].str().c_str(), ss[1].str().c_str());
  }

  Shader::~Shader()
  {
    glDeleteProgram(m_rendererID);
  }

  void Shader::createShader(const char* vertexShaderSource, const char* fragmentShaderSource)
  {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character.
      std::vector<GLchar> infoLog(maxLength);
      glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

      // We don't need the shader anymore.
      glDeleteShader(vertexShader);

      LOG_ERROR("{0}", infoLog.data());
      LOG_ASSERT(false, "Vertex shader compilation failure!");
      return;
    }

    // Create an empty fragment shader handle
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Send the fragment shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, 0);

    // Compile the fragment shader
    glCompileShader(fragmentShader);

    isCompiled = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character.
      std::vector<GLchar> infoLog(maxLength);
      glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

      // We don't need the shader anymore.
      glDeleteShader(fragmentShader);
      // Either of them. Don't leak shaders.
      glDeleteShader(vertexShader);

      LOG_ERROR("{0}", infoLog.data());
      LOG_ASSERT(false, "Fragment shader compilation failure!");
      return;
    }

    // Vertex and fragment shaders are successfully compiled.
    // Now time to link them together into a program.
    // Get a program object.
    m_rendererID = glCreateProgram();

    // Attach our shaders to our program
    glAttachShader(m_rendererID, vertexShader);
    glAttachShader(m_rendererID, fragmentShader);

    // Link our program
    glLinkProgram(m_rendererID);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(m_rendererID, GL_LINK_STATUS, (int*)&isLinked);
    if (isLinked == GL_FALSE)
    {
      GLint maxLength = 0;
      glGetProgramiv(m_rendererID, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character.
      std::vector<GLchar> infoLog(maxLength);
      glGetProgramInfoLog(m_rendererID, maxLength, &maxLength, &infoLog[0]);

      // We don't need the program anymore.
      glDeleteProgram(m_rendererID);
      // Don't leak shaders either.
      glDeleteShader(vertexShader);
      glDeleteShader(fragmentShader);

      LOG_ERROR("{0}", infoLog.data());
      LOG_ASSERT(false, "Shader link failure!");
      return;
    }

    // Always detach shaders after successful link.
    glDetachShader(m_rendererID, vertexShader);
    glDetachShader(m_rendererID, fragmentShader);
  }

  void Shader::bind()
  {
    glUseProgram(m_rendererID);
  }

  void Shader::unbind()
  {
    glUseProgram(m_rendererID);
  }

}