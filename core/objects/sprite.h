#pragma once

//------------------------------------------------------------------//

#include <objects/rendered_object.h>
#include <texture/texture.h>

//------------------------------------------------------------------//

class Sprite : public RenderedObject
{
private:
    void draw(double deltaTime) override;
};

//------------------------------------------------------------------//
