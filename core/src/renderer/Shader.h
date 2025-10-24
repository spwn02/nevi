#pragma once

#include "Core.h"
#include <string>

namespace Core {

  class Shader
  {
  public:
    Shader(const char* filepath);
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void createShader(const char* vertexSource, const char* fragmentSource);
    inline uint32_t getProgram() { return m_rendererID; }

    void bind();
    void unbind();
  private:
    uint32_t m_rendererID;
  };

}