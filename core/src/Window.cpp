#include "Window.h"

#include "platform/OpenGL/OpenGLWindow.h"

#include "renderer/RendererAPI.h"
#include "Core.h"

namespace Core {

  Window* Window::create(const WindowSpecification& specification)
  {
    switch (RendererAPI::getAPI())
    {
    case OpenGL:
      return new OpenGLWindow(specification);
    default:
      LOG_ASSERT(false, "GraphicsAPI({0}} is currently not supported!", (int)RendererAPI::getAPI());
      return nullptr;
    }
  }

}