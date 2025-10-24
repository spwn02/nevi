#include "Application.h"

#include "renderer/RendererAPI.h"

#include <glm/glm.hpp>

namespace Core {
  bool Application::s_running = true;
  bool Application::s_changed = true;
  std::shared_ptr<Input> Application::m_input;

  static Application* s_application = nullptr;

  Application::Application(const ApplicationSpecification& specification, GraphicsAPI graphicsAPI)
    : m_specification(specification)
  {
    s_application = this;

    Log::init();
    std::shared_ptr<Input> m_input = std::make_shared<Input>();
    setGraphicsAPI(graphicsAPI);

    // Set window title to app name if empty
    if (m_specification.windowSpec.title.empty())
      m_specification.windowSpec.title = m_specification.name;

    m_window.reset(Window::create({ "Nevi", 1000, 1000 }));
    m_window->start();

  }

  Application::~Application()
  {
    m_window->shutdown();
    RendererAPI::destroyAPI();
    s_application = nullptr;
  }

  void Application::run()
  {
    float lastTime = getTime();

    while (s_running)
    {
      float currentTime = getTime();
      float timestamp = glm::clamp(currentTime - lastTime, 0.001f, 0.1f);
      lastTime = currentTime;

      if (!s_changed)
      {
        m_window->waitForEvents();
        continue;
      }

      if (m_window->shouldClose())
      {
        shutdown();
        break;
      }

      for (const std::unique_ptr<Layer>& layer : m_layerStack._Get_container())
      {
        layer->onUpdate(timestamp);
      }

      for (const std::unique_ptr<Layer>& layer : m_layerStack._Get_container())
      {
        layer->onRender();
      }

      m_window->update();

      s_changed = false;
    }
  }

  void Application::shutdown()
  {
    s_running = false;
  }

  std::pair<uint32_t, uint32_t> Application::getWindowSize() const
  {
    return m_window->getWindowSize();
  }

  Application& Application::get()
  {
    LOG_ASSERT(s_application, "The application hasn't been initialized yet!");
    return *s_application;
  }

  float Application::getTime()
  {
    return (float)m_window->getTime();
  }
}