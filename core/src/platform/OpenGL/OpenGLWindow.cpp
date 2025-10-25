#include "OpenGLWindow.h"

#include <glad/glad.h>
#include "Core.h"

#include "Application.h"
#include "OpenGLSetup.h"

#include "events/KeyEvents.h"
#include "events/MouseEvents.h"
#include "events/ApplicationEvents.h"

namespace Core {

  OpenGLWindow::OpenGLWindow(WindowSpecification specification)
    : m_specification(specification), m_window(nullptr)
  {
  }

  void OpenGLWindow::start()
  {
    m_window = glfwCreateWindow(m_specification.width, m_specification.height, m_specification.title.c_str(), nullptr, nullptr);
    LOG_ASSERT(m_window, "Failed to create GLFWwindow!");

    glfwMakeContextCurrent(m_window);

    OpenGLSetup::loadGlad();

    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
      switch (action)
      {
        case GLFW_PRESS:
        {
          KeyPressedEvent event(key, scancode, mods, 0);
          Application::onEvent(event);
          break;
        }
        case GLFW_RELEASE:
        {
          KeyReleasedEvent event(key, scancode, mods);
          Application::onEvent(event);
          break;
        }
        case GLFW_REPEAT:
        {
          KeyPressedEvent event(key, scancode, mods, 1);
          Application::onEvent(event);
          break;
        }
      }
    });

    glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode) {
      KeyTypedEvent event(keycode);
      Application::onEvent(event);
      });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
      MouseMovedEvent event(xpos, ypos);
      Application::onEvent(event);
    });

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
      switch (action)
      {
        case GLFW_PRESS:
        {
          MouseButtonPressedEvent event(button, mods);
          Application::onEvent(event);
          break;
        }
        case GLFW_RELEASE:
        {
          MouseButtonReleasedEvent event(button);
          Application::onEvent(event);
          break;
        }
      }
    });

    glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
      MouseScrolledEvent event(xoffset, yoffset);
      Application::onEvent(event);
    });

    setVSync(m_specification.VSync);

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
      WindowCloseEvent event(window);
      Application::onEvent(event);
    });

    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
      WindowResizeEvent event(window, width, height);
      Application::onEvent(event);
    });

    glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focused) {
      if (focused == GL_TRUE)
      {
        WindowFocusEvent event(window);
        Application::onEvent(event);
      }
      else
      {
        WindowLostFocusEvent event(window);
        Application::onEvent(event);
      }
    });

    glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int xpos, int ypos) {
      WindowMovedEvent event(window, xpos, ypos);
      Application::onEvent(event);
    });
  }

  OpenGLWindow::~OpenGLWindow()
  {
    shutdown();
  }

  void OpenGLWindow::shutdown()
  {
    if (m_window)
      glfwDestroyWindow(m_window);

    m_window = nullptr;
  }

  void OpenGLWindow::update()
  {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
  }

  std::pair<int32_t, int32_t> OpenGLWindow::getWindowSize()
  {
    int width, height;
    glfwGetWindowSize(m_window, &width, &height);
    return { width, height };
  }

  void OpenGLWindow::setVSync(bool enabled)
  {
    m_specification.VSync = enabled;
    enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
  }

}