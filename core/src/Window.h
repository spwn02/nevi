#pragma once

#include <string>
#include <numbers>
#include "events/Event.h"

namespace Core {

  struct WindowSpecification
  {
    std::string title = "Application";
    uint32_t width = 1280;
    uint32_t height = 720;
    bool isResizeable = true;
    bool VSync = true;
  };

  class Window
  {
  public:
    virtual ~Window() = default;

    virtual void start() = 0;
    virtual void shutdown() = 0;
    virtual void update() = 0;
    virtual inline void waitForEvents() = 0;
    virtual bool shouldClose() const = 0;

    virtual inline void* get() = 0;
    virtual inline std::pair<uint32_t, uint32_t> getWindowSize() = 0;
    virtual inline float getTime() const = 0;

    virtual inline void setVSync(bool enabled = true) = 0;

    static Window* create(const WindowSpecification& specific = WindowSpecification());
  private:
    WindowSpecification m_specification;
  };

}