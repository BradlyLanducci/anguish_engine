#pragma once

//------------------------------------------------------------------//

#include <objects/rendered_object.h>
#include <texture/spritesheet.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <ogl/ebo.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class AnimatedSprite : public RenderedObject
{
public:
    AnimatedSprite();

    void idleUpdate(double deltaTime);

    std::string currentAnimation() const;

    void addAnimation(const std::string &animation, Shared<Spritesheet> spritesheet);
    void playAnimation(const std::string &animation);
    void stopAnimation();

private:
    using RenderedObject::setSize;
    using RenderedObject::setTexture;

    void draw() override;

    std::unordered_map<std::string, Shared<Spritesheet>> m_animations;
    std::string m_currentAnimation;
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
