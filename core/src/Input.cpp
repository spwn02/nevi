#include "Input.h"

#include "Application.h"

#include "Utils.h"

namespace Core {

  std::unique_ptr<EventDispatcher> Input::m_dispatcher{};

  Input::Input()
  {
    m_dispatcher->subscribe<KeyPressedEvent>([this](const KeyPressedEvent& e) { this->keyPressedEvent(e); });
    //m_dispatcher->subscribe<KeyReleasedEvent>([this](const KeyReleasedEvent& e) { this->keyReleasedEvent(e); });
    //m_dispatcher->subscribe<KeyTypedEvent>([this](const KeyTypedEvent& e) { this->keyTypedEvent(e); });
    //m_dispatcher->subscribe<MouseMovedEvent>([this](const MouseMovedEvent& e) { this->mouseMovedEvent(e); });
    //m_dispatcher->subscribe<MouseScrolledEvent>([this](const MouseScrolledEvent& e) { this->mouseScrolledEvent(e); });
    //m_dispatcher->subscribe<MouseButtonPressedEvent>([this](const MouseButtonPressedEvent& e) { this->mouseButtonPressedEvent(e); });
    //m_dispatcher->subscribe<MouseButtonReleasedEvent>([this](const MouseButtonReleasedEvent& e) { this->mouseButtonReleasedEvent(e); });
  }

  void Input::keyPressedEvent(const KeyPressedEvent& e)
  {
    if (e.keyCode == 256)
      Application::shutdown();
  }

  void Input::keyReleasedEvent(const KeyReleasedEvent& e)
  {
    LOG_TRACE(e.toString());
  }

  void Input::keyTypedEvent(const KeyTypedEvent& e)
  {
    //LOG_TRACE(e.toString());
  }

  void Input::mouseMovedEvent(const MouseMovedEvent& e)
  {
    LOG_TRACE(e.toString());
  }

  void Input::mouseScrolledEvent(const MouseScrolledEvent& e)
  {
    LOG_TRACE(e.toString());
  }

  void Input::mouseButtonPressedEvent(const MouseButtonPressedEvent& e)
  {
    LOG_TRACE(e.toString());
  }

  void Input::mouseButtonReleasedEvent(const MouseButtonReleasedEvent& e)
  {
    LOG_TRACE(e.toString());
  }

}