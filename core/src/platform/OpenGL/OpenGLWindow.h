#pragma once

#include "Window.h"
#include <GLFW/glfw3.h>

#include "memory.h"

namespace Core {

  class OpenGLWindow : public Window
  {
  public:
    OpenGLWindow(WindowSpecification specification);
    virtual ~OpenGLWindow() override;

    virtual void start() override;
    virtual void shutdown() override;
    virtual void update() override;
    virtual inline void waitForEvents() override { glfwWaitEvents(); }
    virtual bool shouldClose() const override { return glfwWindowShouldClose(m_window); }

    virtual inline void* get() override { return m_window; }
    virtual inline std::pair<uint32_t, uint32_t> getWindowSize() override;
    virtual inline float getTime() const { return (float)glfwGetTime(); };

    virtual void setVSync(bool enabled) override;
  private:
    WindowSpecification m_specification;

    GLFWwindow* m_window;
  };

}