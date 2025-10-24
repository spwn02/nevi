#pragma once

#include "Event.h"

#include <sstream>

struct MouseMovedEvent : Event
{
  double x, y;

  explicit MouseMovedEvent(double x, double y)
    : x(x), y(y) { }

  const std::string toString() const override
  {
    std::stringstream ss;
    ss << "MouseMovedEvent: " << x << ", " << y;
    return ss.str();
  }

  EVENT_CLASS_TYPE(EventType::MouseMoved)
};

struct MouseScrolledEvent : Event
{
  double x, y;

  explicit MouseScrolledEvent(double x, double y)
    : x(x), y(y) { }

  const std::string toString() const override
  {
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << x << ", " << y;
    return ss.str();
  }

  EVENT_CLASS_TYPE(EventType::MouseScrolled)
};

struct MouseButtonEvent : Event
{
  int button;

  explicit MouseButtonEvent(int button)
    : button(button) { }
};

struct MouseButtonPressedEvent : MouseButtonEvent
{
  int mods;

  MouseButtonPressedEvent(int button, int mods)
    : MouseButtonEvent(button), mods(mods) { }

  const std::string toString() const override
  {
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << button;
    return ss.str();
  }

  EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
};

struct MouseButtonReleasedEvent : MouseButtonEvent
{
  MouseButtonReleasedEvent(int button)
    : MouseButtonEvent(button) { }

  const std::string toString() const override
  {
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << button;
    return ss.str();
  }

  EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
};