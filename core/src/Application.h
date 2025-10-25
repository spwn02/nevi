#pragma once

#include <stack>

#include "Window.h"
#include "Layer.h"

#include "renderer/RendererAPI.h"

namespace Core {
  struct ApplicationSpecification
  {
    std::string name = "Application";
    WindowSpecification windowSpec;
  };

  class Application
  {
  public:
    Application(const ApplicationSpecification& specification = ApplicationSpecification(), GraphicsAPI graphicsAPI = GraphicsAPI::OpenGL);
    ~Application();

    void run();
    static void shutdown();

    inline void setGraphicsAPI(GraphicsAPI graphicsAPI) { RendererAPI::setAPI(graphicsAPI); }

    template<typename TLayer>
    requires(std::is_base_of_v<Layer, TLayer>)
    void pushLayer()
    {
      std::unique_ptr<Layer> layer = std::make_unique<TLayer>();
      layer->onAttach();
      m_layerStack.push(std::move(layer));
    }

    static void onEvent(Event& event);

    std::pair<uint32_t, uint32_t> getWindowSize() const;

    static Application& get();

    inline Window& getWindow() { return *m_window; };

    float getTime();
  private:
    static Application* s_application;
    static bool s_running;

    ApplicationSpecification m_specification;
    std::shared_ptr<Window> m_window;
    std::stack<std::unique_ptr<Layer>> m_layerStack;
  };
}