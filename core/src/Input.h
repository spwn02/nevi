#pragma once

#include <memory>

#include "events/EventDispatcher.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"

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
  private:
    static std::unique_ptr<EventDispatcher> m_dispatcher;
  };

}