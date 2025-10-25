#include "AppLayer.h"

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

  constexpr float vertices[] = {
    // Position                        |  Color
     0.5f / 2 - 0.5f,  0.5f / 2, 0.0f,    1.0f, 1.0f, 0.3f, 1.0f,
     0.5f / 2 - 0.5f, -0.5f / 2, 0.0f,    1.0f, 0.6f, 1.0f, 1.0f,
    -0.5f / 2 - 0.5f, -0.5f / 2, 0.0f,    1.0f, 1.0f, 0.9f, 1.0f,
    -0.5f / 2 - 0.5f,  0.5f / 2, 0.0f,    1.0f, 0.8f, 1.0f, 1.0f,

    // Position                        |  Color
     0.5f / 2 + 0.5f,  0.5f / 2, 0.0f,    0.9f, 1.0f, 1.0f, 1.0f,
     0.5f / 2 + 0.5f, -0.5f / 2, 0.0f,    1.0f, 0.6f, 1.0f, 1.0f,
    -0.5f / 2 + 0.5f, -0.5f / 2, 0.0f,    0.3f, 1.0f, 1.0f, 1.0f,
    -0.5f / 2 + 0.5f,  0.5f / 2, 0.0f,    1.0f, 0.8f, 1.0f, 1.0f,
  };

  m_vertexBuffer.reset(Core::VertexBuffer::create((float*)vertices, sizeof(vertices)));
  m_vertexBuffer->setLayout(layout);

  m_indexBuffer.reset(Core::IndexBuffer::create({
    0, 1, 3, 1, 2, 3,
    4, 5, 7, 5, 6, 7
  }));

  m_vertexArray.reset(Core::VertexArray::create());
  m_vertexArray->addVertexBuffer(m_vertexBuffer, m_shader->getProgram());
  m_vertexArray->setIndexBuffer(m_indexBuffer);
}

void AppLayer::onAttach()
{
  Core::LOG_INFO("AppLayer: Attached!");
}

void AppLayer::onDetach()
{
  Core::LOG_INFO("AppLayer: Detached!");
}

void AppLayer::onEvent(Core::Event& event)
{
  if (event.getType() == Core::EventType::KeyPressed && ((Core::KeyEvent&)event).keyCode == 256)
  {
    event.handled = true;
    Core::Application::shutdown();
  }
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