#include "AppLayer.h"

#include "Application.h"

#include <glm/glm.hpp>

AppLayer::AppLayer()
{
  // Create shaders
  m_shader.reset(new Core::Shader("triangle.shader"));

  // Create geometry
  m_renderer.reset(Core::Renderer::create());

  Core::BufferLayout layout = {
    { Core::DataType::Float3, "v_position" },
    { Core::DataType::Float4, "v_color" }
  };

  float vertices[] = {
    -0.25f,  0.25f, 0.0f, 1.0f, 1.0f, 0.3f, 1.0f,
    -0.25f, -0.25f, 0.0f, 1.0f, 0.6f, 1.0f, 1.0f,
    -0.75f, -0.25f, 0.0f, 1.0f, 1.0f, 0.9f, 1.0f,
    -0.75f,  0.25f, 0.0f, 1.0f, 0.8f, 1.0f, 1.0f,


    -0.25f + 1,  0.25f, 0.0f, 0.9f, 1.0f, 1.0f, 1.0f,
    -0.25f + 1, -0.25f, 0.0f, 1.0f, 0.6f, 1.0f, 1.0f,
    -0.75f + 1, -0.25f, 0.0f, 0.3f, 1.0f, 1.0f, 1.0f,
    -0.75f + 1,  0.25f, 0.0f, 1.0f, 0.8f, 1.0f, 1.0f,
  };

  m_vertexBuffer.reset(Core::VertexBuffer::create(vertices, sizeof(vertices)));
  m_vertexBuffer->setLayout(layout);

  m_indexBuffer.reset(Core::IndexBuffer::create({
    0, 1, 3, 1, 2, 3,
    4, 5, 7, 5, 6, 7
  }));

  m_vertexArray.reset(Core::VertexArray::create());
  m_vertexArray->addVertexBuffer(m_vertexBuffer, m_shader->getProgram());
  m_vertexArray->setIndexBuffer(m_indexBuffer);

  //m_renderer->clearColor(20, 20, 20, 255);
}

void AppLayer::onUpdate(float ts)
{

}

void AppLayer::onRender()
{
  //auto [width, height] = m_window->getWindowSize();

  //m_renderer->setViewport(0, 0, width, height);

  m_renderer->clearColor(20, 20, 20, 255);
  m_renderer->clear();

  m_renderer->drawIndexed(m_vertexArray, m_shader);
}