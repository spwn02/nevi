#include "Buffer.h"
#include <glad/glad.h>

#include <renderer/RendererAPI.h>
#include <platform/OpenGL/OpenGLBuffer.h>

namespace Core {

  VertexBuffer* VertexBuffer::create(const std::initializer_list<float>& vertices)
  {
    return create((float*)vertices.begin(), (uint32_t)vertices.size() * sizeof(float));
  }

  VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size)
  {
    switch (RendererAPI::getAPI())
    {
    case GraphicsAPI::OpenGL:
      return new OpenGLVertexBuffer(vertices, size);
    case GraphicsAPI::Vulcan:
      LOG_ASSERT(false, "Vulcan API is currently not supported!");
      return nullptr;
    }

    LOG_ASSERT(false, "Unknown Renderer GraphicsAPI!");
    return nullptr;
  }

  IndexBuffer* IndexBuffer::create(const std::initializer_list<uint32_t>& indices)
  {
    return create((uint32_t*)indices.begin(), (uint32_t)indices.size() * sizeof(uint32_t));
  }

  IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t size)
  {
    switch (RendererAPI::getAPI())
    {
    case GraphicsAPI::OpenGL:
      return new OpenGLIndexBuffer(indices, size);
    case GraphicsAPI::Vulcan:
      LOG_ASSERT(false, "Vulcan API is currently not supported!");
      return nullptr;
    }

    LOG_ASSERT(false, "Unknown Renderer GraphicsAPI!");
    return nullptr;
  }

}