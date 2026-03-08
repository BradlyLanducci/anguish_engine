#include <objects/animated_sprite.h>
#include <renderer/rendering_manager.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>
#include <ogl/vertices.h>

//------------------------------------------------------------------//

AnimatedSprite::AnimatedSprite()
    : RenderedObject(true, false)
{
    shader().setVertexShader("core/shaders/anim_vert.glsl");
}

//------------------------------------------------------------------//

void AnimatedSprite::idleUpdate(double deltaTime)
{
    if (!m_currentAnimation.empty())
    {
        auto &sheet{ m_animations.at(m_currentAnimation) };
        if (sheet->isComplete())
        {
            m_currentAnimation = "";
        }
        else
        {
            Vector2i currentFrame{ sheet->getCurrentFrame(deltaTime) };
            shader().p_vertexShader->setVec2i("currentFrame", currentFrame);
        }
    }
}

//------------------------------------------------------------------//

void AnimatedSprite::addAnimation(const std::string &animation, Shared<Spritesheet> spritesheet)
{
    ShaderProgram &s{ shader() };
    s.p_vertexShader->setVec2i("dimensions", { spritesheet->columns(), spritesheet->rows() });
    s.p_vertexShader->setInt("numFrames", spritesheet->numFrames());
    s.p_vertexShader->setVec2("frameSize", spritesheet->frameSize());

    setSize(spritesheet->texture().size() * spritesheet->frameSize());

    m_animations.try_emplace(animation, spritesheet);
}

//------------------------------------------------------------------//

void AnimatedSprite::playAnimation(const std::string &animation)
{
    if (animation == m_currentAnimation)
    {
        return;
    }

    if (m_animations.contains(animation))
    {
        if (!m_currentAnimation.empty())
        {
            auto &current{ m_animations.at(m_currentAnimation) };
            current->stop();
        }

        m_currentAnimation = animation;

        auto &sheet{ m_animations.at(m_currentAnimation) };
        sheet->start();
    }
    else
    {
        Log(Error) << animation << " doesn't exist in the animation sprite.";
    }
}

//------------------------------------------------------------------//

void AnimatedSprite::draw(double deltaTime)
{
    if (!m_currentAnimation.empty())
    {
        auto translatedModel{ glm::translate(m_model, glm::dvec3(globalPosition().x, globalPosition().y, 1.0)) };
        auto rotatedModel{ glm::rotate(translatedModel, rotation(), glm::dvec3(0.0, 0.0, 1.0)) };
        auto scaledModel{ glm::scale(rotatedModel, glm::dvec3(size().x * scale().x, size().y * scale().y, 1.0)) };

        m_shaderProgram.p_vertexShader->setMat4("model", scaledModel);

        glUseProgram(m_shaderProgram.get());
        glBindVertexArray(m_vao.get());

        auto &sheet{ m_animations.at(m_currentAnimation) };
        if (!sheet->isComplete())
        {
            sheet->texture().bind();
        }

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        checkGLError();
    }
}

//------------------------------------------------------------------//