#include "OpenGLRenderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Core {

  void OpenGLRenderer::clear() const
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  void OpenGLRenderer::clearColor(int r, int g, int b, int a) const
  {
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
  }

  void OpenGLRenderer::clearColor(float r, float g, float b, float a) const
  {
    glClearColor(r, g, b, a);
  }

  void OpenGLRenderer::setViewport(int32_t x, int32_t y, int32_t width, int32_t height) const
  {
    glViewport(0, 0, width, height);
  }

  void OpenGLRenderer::drawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) const
  {
    shader->bind();
    vertexArray->bind();
    shader->unbind();

    glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

    vertexArray->unbind();
  }

}