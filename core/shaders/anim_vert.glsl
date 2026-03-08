#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform int numFrames;
uniform vec2 frameSize;
uniform ivec2 currentFrame;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TexCoord;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 0.0, 1.0);

    if (numFrames > 0) {
        vec2 inCoord = vec2(aTexCoord.x / float(numFrames), aTexCoord.y);
        TexCoord = inCoord + currentFrame * frameSize;
    }
}
