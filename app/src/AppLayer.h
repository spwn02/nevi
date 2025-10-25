#pragma once

#include <Core.h>

class AppLayer : public Core::Layer
{
public:
  AppLayer();
  virtual ~AppLayer() {};

  virtual void onAttach() override;
  virtual void onDetach() override;
  virtual void onEvent(Core::Event& event) override;

  virtual void onUpdate(float ts) override;
  virtual void onRender() override;
private:
  std::shared_ptr<Core::Shader> m_shader;
  std::shared_ptr<Core::Renderer> m_renderer;
  std::shared_ptr<Core::VertexArray> m_vertexArray;
  std::shared_ptr<Core::VertexBuffer> m_vertexBuffer;
  std::shared_ptr<Core::IndexBuffer> m_indexBuffer;
};