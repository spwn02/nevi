#pragma once

#include "Layer.h"
#include "renderer/Renderer.h"
#include "renderer/Shader.h"

class AppLayer : public Core::Layer
{
public:
  AppLayer();
  virtual ~AppLayer() {};

  virtual void onUpdate(float ts) override;
  virtual void onRender() override;
private:
  std::shared_ptr<Core::Shader> m_shader;
  std::shared_ptr<Core::Renderer> m_renderer;
  std::shared_ptr<Core::VertexArray> m_vertexArray;
  std::shared_ptr<Core::VertexBuffer> m_vertexBuffer;
  std::shared_ptr<Core::IndexBuffer> m_indexBuffer;
};