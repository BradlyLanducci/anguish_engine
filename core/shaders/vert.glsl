#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec2 globalPos;
uniform vec2 spriteSize;

out vec2 TexCoord;

void main()
{
    vec2 scaledPos = aPos * spriteSize + globalPos;
    gl_Position = projection * view * model * vec4(scaledPos, 0.0, 1.0);
    TexCoord = aTexCoord;
}
