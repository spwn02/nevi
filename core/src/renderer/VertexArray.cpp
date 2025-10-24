#include "VertexArray.h"
#include "renderer/RendererAPI.h"

#include "platform/OpenGL/OpenGLVertexArray.h"

namespace Core {

  VertexArray* VertexArray::create()
  {
    switch (RendererAPI::getAPI())
    {
    case OpenGL:
      return new OpenGLVertexArray();
    case Vulcan:
      LOG_ASSERT(false, "Vulcan API is currently not supported!");
      return nullptr;
    }

    LOG_ASSERT(false, "Unknown Renderer GraphicsAPI!");
    return nullptr;
  }

}