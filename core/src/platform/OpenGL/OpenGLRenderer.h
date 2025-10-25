#pragma once

#include "renderer/Renderer.h"

namespace Core {

  class OpenGLRenderer : public Renderer
  {
  public:
    virtual void clear() const override;
    virtual void clearColor(int32_t r, int32_t g, int32_t b, int32_t a) const override;
    virtual void clearColor(float r, float g, float b, float a) const override;
    virtual void setViewport(int32_t x, int32_t y, int32_t width, int32_t height) const override;
    virtual void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) const override;
  };

}