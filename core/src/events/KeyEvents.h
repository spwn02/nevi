#pragma once

#include "Event.h"

#include <sstream>

namespace Core {

  struct KeyEvent : Event
  {
    int keyCode;

    explicit KeyEvent(int keyCode)
      : keyCode(keyCode) {
    }
  };

  struct KeyPressedEvent : KeyEvent
  {
    int scanCode, mods, repeatCount;

    explicit KeyPressedEvent(int keyCode, int scanCode, int mods, int repeatCount)
      : KeyEvent(keyCode), scanCode(scanCode), mods(mods), repeatCount(repeatCount) {
    };

    const std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyPressed)
  };

  struct KeyReleasedEvent : KeyEvent
  {
    int scanCode, mods;

    explicit KeyReleasedEvent(int keyCode, int scanCode, int mods)
      : KeyEvent(keyCode), scanCode(scanCode), mods(mods) {
    };

    const std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyReleasedEvent: " << keyCode;
      return ss.str();
    };

    EVENT_CLASS_TYPE(EventType::KeyReleased)
  };

  struct KeyTypedEvent : KeyEvent
  {
    explicit KeyTypedEvent(unsigned int keyCode)
      : KeyEvent(keyCode) {
    }

    const std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyTypedEvent: " << keyCode;
      return ss.str();
    };

    EVENT_CLASS_TYPE(EventType::KeyTyped)
  };

}