#pragma once

#include "renderer/Renderer.h"

namespace Core {

  class OpenGLRenderer : public Renderer
  {
  public:
    virtual void clear() const override;
    virtual void clearColor(int r, int g, int b, int a) const override;
    virtual void clearColor(float r, float g, float b, float a) const override;
    virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const override;
    virtual void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) const override;
  };

}