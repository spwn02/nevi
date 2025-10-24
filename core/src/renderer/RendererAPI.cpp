#include "RendererAPI.h"

#include "Core.h"

#include "platform/OpenGL/OpenGLSetup.h"

namespace Core {

  GraphicsAPI RendererAPI::s_API = None;


  void RendererAPI::setAPI(GraphicsAPI API)
  {
    if (s_API == API) return LOG_TRACE("GraphicsAPI is already set to {0}", (int)API);

    GraphicsAPI oldAPI = s_API;

    switch (API)
    {
    case None:
      LOG_ASSERT(false, "Use RendererAPI::destroyAPI() instead of RendererAPI::setAPI(None)!");
      return;
    case OpenGL:
      OpenGLSetup::setup();
      break;
    default:
      LOG_ASSERT(false, "GraphicsAPI({0}) is currently not supported!", (int)API);
      return;
    }

    if (oldAPI != None) destroyAPI();
    s_API = API;
  }

  void RendererAPI::destroyAPI()
  {
    switch (s_API)
    {
    case None:
      LOG_ASSERT(false, "GraphicsAPI is not set yet!");
      break;
    case OpenGL:
      OpenGLSetup::shutdown();
      break;
    default:
      LOG_ASSERT(false, "Unknown GraphicsAPI!");
      return;
    }

    s_API = None;
  }

}