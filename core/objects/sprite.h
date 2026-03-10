#pragma once

//------------------------------------------------------------------//

#include <objects/rendered_object.h>
#include <texture/texture.h>

//------------------------------------------------------------------//

class Sprite : public RenderedObject
{
public:
    Sprite();

    void draw(double deltaTime) override;
};

//------------------------------------------------------------------//
