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
    virtual void clearColor(int r, int g, int b, int a) const = 0;
    virtual void clearColor(float r, float g, float b, float a) const = 0;
    virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const = 0;
    virtual void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) const = 0;

    inline static GraphicsAPI getAPI() { return RendererAPI::getAPI(); }

    static Renderer* create();
  };

}