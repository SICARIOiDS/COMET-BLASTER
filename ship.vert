#version 460 core

layout (location = 0) in vec2 iPos;
layout (location = 1) in vec3 iColor;

out vec3 Color;

void main()
{
   gl_Position = vec4(iPos.x, iPos.y, 1.0, 1.0);
   Color = iColor;
}
