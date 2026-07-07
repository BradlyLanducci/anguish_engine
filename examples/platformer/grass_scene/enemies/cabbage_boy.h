#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/character.h>
#include <objects/animated_sprite.h>

//------------------------------------------------------------------//

class CabbageBoy : public AE::Character
{
public:
    CabbageBoy();

private:
    void physicsUpdate(double deltaTime);
    AE::AnimatedSprite *mp_sprite;
};

//------------------------------------------------------------------//
