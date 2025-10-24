#pragma once

#include "events/Event.h"

namespace Core {

  class Layer
  {
  public:
    virtual ~Layer() = default;

    virtual void onEvent(Event& event) {}

    virtual void onUpdate(float ts) {}
    virtual void onRender() {}
  };

}