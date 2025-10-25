#include "Application.h"

#include "renderer/RendererAPI.h"

#include "Utils.h"

#include <glm/glm.hpp>

namespace Core {

  Application* Application::s_application = nullptr;
  bool Application::s_running = false;

  Application::Application(const ApplicationSpecification& specification, GraphicsAPI graphicsAPI)
    : m_specification(specification)
  {
    s_application = this;

    Log::init();
    setGraphicsAPI(graphicsAPI);

    // Set window title to app name if empty
    if (m_specification.windowSpec.title.empty())
      m_specification.windowSpec.title = m_specification.name;

    m_window.reset(Window::create(specification.windowSpec));
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
    s_running = true;

    float lastTime = getTime();

    while (s_running)
    {
      float currentTime = getTime();
      float timestamp = glm::clamp(currentTime - lastTime, 0.001f, 0.1f);
      lastTime = currentTime;

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
    }
  }

  void Application::shutdown()
  {
    s_running = false;
  }

  void Application::onEvent(Event& event)
  {
    for (const std::unique_ptr<Layer>& layer : Application::get().m_layerStack._Get_container())
    {
      layer->onEvent(event);
      if (event.handled) break;
    }
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