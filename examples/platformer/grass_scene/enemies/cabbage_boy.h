#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/character.h>
#include <objects/animated_sprite.h>

//------------------------------------------------------------------//

class CabbageBoy : public Character
{
public:
    CabbageBoy();

private:
    void physicsUpdate(double deltaTime);
    AnimatedSprite *mp_sprite;
};

//------------------------------------------------------------------//
