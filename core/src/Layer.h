#pragma once

#include "events/Event.h"

namespace Core {

  class Layer
  {
  public:
    Layer(const std::string& name = "Layer")
      : m_name(name) { }
    virtual ~Layer() = default;

    virtual void onAttach() {}
    virtual void onDetach() {}
    virtual void onEvent(Event& event) {}

    virtual void onUpdate(float ts) {}
    virtual void onRender() {}

    inline const std::string& getName() const { return m_name; }
  protected:
    std::string m_name;
  };

}