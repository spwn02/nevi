#pragma once

namespace Core {

  enum GraphicsAPI
  {
    None = 0, OpenGL, Vulcan
  };

  class RendererAPI
  {
  public:
    inline static GraphicsAPI getAPI() { return s_API; }
    static void setAPI(GraphicsAPI API);
    static void destroyAPI();
    static void init();
  private:
    static GraphicsAPI s_API;
  };

}