#pragma once

//------------------------------------------------------------------//

#include <objects/rendered_object.h>
#include <texture/spritesheet.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <ogl/ebo.h>
#include <utilities/shared.h>

//------------------------------------------------------------------//

class AnimatedSprite : public RenderedObject
{
public:
    AnimatedSprite();

    void idleUpdate(double deltaTime);

    void addAnimation(const std::string &animation, Shared<Spritesheet> spritesheet);
    void playAnimation(const std::string &animation);

    void draw(double deltaTime) override;

private:
    using RenderedObject::setSize;
    using RenderedObject::setTexture;

    std::unordered_map<std::string, Shared<Spritesheet>> m_animations;
    std::string m_currentAnimation;
};

//------------------------------------------------------------------//
