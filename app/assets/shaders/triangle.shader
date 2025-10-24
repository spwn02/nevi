#shader vertex
#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec4 v_color;

out vec4 o_color;

void main()
{
  gl_Position = vec4(v_position, 1.0);
  o_color = v_color;
}

#shader fragment
#version 330

layout(location = 0) out vec4 color;

in vec4 o_color;

void main()
{
  color = vec4(o_color);
}