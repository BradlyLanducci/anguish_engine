#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/collision_object.h>
#include <objects/sprite_object.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
    Character();
    ~Character() override = default;

    void physicsUpdate(float delta) override;

private:
    Sprite *mp_sprite;
    CollisionObject *mp_collision;
    Jumper m_jumper;
};

//------------------------------------------------------------------//
