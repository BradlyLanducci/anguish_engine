#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/collision.h>
#include <objects/animated_sprite.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
    Character();
    ~Character() override = default;

    void physicsUpdate(double delta) override;

private:
    AnimatedSprite *mp_sprite;
    Collision *mp_collision;
    Jumper m_jumper;
};

//------------------------------------------------------------------//
