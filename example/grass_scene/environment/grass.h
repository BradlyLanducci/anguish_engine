#pragma once

//------------------------------------------------------------------//

#include <objects/collision_object.h>
#include <objects/sprite_object.h>

//------------------------------------------------------------------//

class Grass : public Object
{
public:
    Grass();
    ~Grass() override = default;

    void idleUpdate(float delta) override;
    void physicsUpdate(float delta) override;

private:
    Sprite *m_sprite;
    CollisionObject *m_collision;
};

//------------------------------------------------------------------//
