#include "Renderer.h"

#include "platform/OpenGL/OpenGLRenderer.h"

namespace Core {

  Renderer* Renderer::create()
  {
    switch (getAPI())
    {
    case None:
      LOG_ASSERT(false, "Renderer GraphicsAPI is not initialized!");
      return nullptr;
    case OpenGL:
      return new OpenGLRenderer();
    default:
      LOG_ASSERT(false, "The chosen Renderer GraphicsAPI is currently not supported!");
      return nullptr;
    }
  }

}