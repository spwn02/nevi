#pragma once

#include "Core.h"

class ImGuiLayer : public Core::Layer
{
public:
  ImGuiLayer();
  virtual ~ImGuiLayer() {};

  virtual void onAttach() override;
  virtual void onDetach() override;
  virtual void onEvent(Core::Event& event) override;

  virtual void onUpdate(float ts) override;
  virtual void onRender() override;
};