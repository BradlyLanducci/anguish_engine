#pragma once

//------------------------------------------------------------------//

#include <objects/rendered_object.h>
#include <texture/texture.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <ogl/ebo.h>

//------------------------------------------------------------------//

class AnimatedSprite : public RenderedObject
{
public:
    AnimatedSprite();
    ~AnimatedSprite();

    void idleUpdate(double delta) override;

private:
    int m_currentFrame{};
    double m_accumulator{};
};

//------------------------------------------------------------------//
