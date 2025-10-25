#pragma once

#include <memory>

#include "events/EventDispatcher.h"
#include "events/KeyEvents.h"
#include "events/MouseEvents.h"
#include "events/ApplicationEvents.h"

namespace Core {

  class Input
  {
  public:
    Input();

    static inline void emit(const Event& e)
    {
      m_dispatcher->emit(e);
    }
  private:
    void keyPressedEvent(const KeyPressedEvent& e);
    void keyReleasedEvent(const KeyReleasedEvent& e);
    void keyTypedEvent(const KeyTypedEvent& e);
    void mouseMovedEvent(const MouseMovedEvent& e);
    void mouseScrolledEvent(const MouseScrolledEvent& e);
    void mouseButtonPressedEvent(const MouseButtonPressedEvent& e);
    void mouseButtonReleasedEvent(const MouseButtonReleasedEvent& e);
    void windowCloseEvent(const WindowCloseEvent& e);
    void windowResizeEvent(const WindowResizeEvent& e);
    void windowFocusEvent(const WindowFocusEvent& e);
    void windowLostFocusEvent(const WindowLostFocusEvent& e);
    void windowMovedEvent(const WindowMovedEvent& e);
  private:
    static std::unique_ptr<EventDispatcher> m_dispatcher;
  };

}