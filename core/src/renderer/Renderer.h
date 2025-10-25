#pragma once

#include <stdint.h>
#include <memory>

#include "RendererAPI.h"
#include "VertexArray.h"
#include "Shader.h"

namespace Core {

  class Renderer
  {
  public:
    virtual void clear() const = 0;
    virtual void clearColor(int32_t r, int32_t g, int32_t b, int32_t a) const = 0;
    virtual void clearColor(float r, float g, float b, float a) const = 0;
    virtual void setViewport(int32_t x, int32_t y, int32_t width, int32_t height) const = 0;
    virtual void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) const = 0;

    inline static GraphicsAPI getAPI() { return RendererAPI::getAPI(); }

    static Renderer* create();
  };

}