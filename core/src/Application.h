#pragma once

#include <stack>

#include "Input.h"
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
    void shutdown();

    inline void setGraphicsAPI(GraphicsAPI graphicsAPI) { RendererAPI::setAPI(graphicsAPI); }

    template<typename TLayer>
    requires(std::is_base_of_v<Layer, TLayer>)
    void pushLayer()
    {
      m_layerStack.push(std::make_unique<TLayer>());
    }

    static void onEvent(const Event& event)
    {
      m_input->emit(event);
      s_changed = true;
    }

    std::pair<uint32_t, uint32_t> getWindowSize() const;

    static Application& get();
    float getTime();
  private:
    ApplicationSpecification m_specification;
    static bool s_running;
    static bool s_changed;

    static std::shared_ptr<Input> m_input;
    std::shared_ptr<Window> m_window;
    std::stack<std::unique_ptr<Layer>> m_layerStack;
  };
}