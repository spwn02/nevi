#pragma once

#include <string>

#include "Core.h"

enum class EventType : int
{
  None = 0,
  WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
  AppTick, AppUpdate, AppRender,
  KeyPressed, KeyReleased, KeyTyped,
  MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
};

//enum class EventCategory : int
//{
//  None        = 0,
//  Application = 1 << 0,
//  Input       = 1 << 1,
//  Keyboard    = 1 << 2,
//  Mouse       = 1 << 3,
//  MouseButton = 1 << 4,
//};

struct Event
{
  Event() = default;
  virtual ~Event() = default;

  virtual EventType getType() const = 0;
  static EventType getStaticType() { return EventType::None; };
  virtual const char* getName() const = 0;
  static const char* getStaticName() { return reinterpret_cast<const char*>(EventType::None); };

  virtual const std::string toString() const { return getName(); }
};

#define EVENT_CLASS_TYPE(t) static EventType getStaticType() { return (t); }\
                            virtual EventType getType() const override { return getStaticType(); }\
                            static const char* getStaticName() { return #t; }\
                            virtual const char* getName() const override { return getStaticName(); }