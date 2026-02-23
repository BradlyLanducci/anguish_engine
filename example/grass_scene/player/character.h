#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/collision.h>
#include <objects/sprite.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
    Character();
    ~Character() override = default;

    void physicsUpdate(float delta) override;

private:
    Sprite *mp_sprite;
    Collision *mp_collision;
    Jumper m_jumper;
};

//------------------------------------------------------------------//
