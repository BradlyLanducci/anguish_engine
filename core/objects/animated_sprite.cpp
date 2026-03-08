#include <objects/animated_sprite.h>
#include <renderer/rendering_manager.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>
#include <ogl/vertices.h>

//------------------------------------------------------------------//

AnimatedSprite::AnimatedSprite()
    : RenderedObject(true, false)
{
    ShaderProgram &s{ shader() };
    s.setVertexShader("core/shaders/anim_vert.glsl");

    s.p_vertexShader->setInt("numFrames", 2);
    s.p_vertexShader->setVec2("frameSize", Vector2(0.5f, 1.f));
    s.p_vertexShader->setVec2i("currentFrame", Vector2i(0, 0));
}

//------------------------------------------------------------------//

AnimatedSprite::~AnimatedSprite()
{
    RenderingManager::get().removeObject(this);
}

//------------------------------------------------------------------//

void AnimatedSprite::idleUpdate(double deltaTime)
{
    m_accumulator += deltaTime;

    if (m_accumulator >= 0.5f)
    {
        m_currentFrame = m_currentFrame == 0 ? 1 : 0;
        shader().p_vertexShader->setVec2i("currentFrame", Vector2i(m_currentFrame, 0));
        m_accumulator = 0.f;
    }
}

//------------------------------------------------------------------//
