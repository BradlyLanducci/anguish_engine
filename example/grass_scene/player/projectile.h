#pragma once

//------------------------------------------------------------------//

#include <objects/sprite.h>

#include <objects/collision.h>

//------------------------------------------------------------------//

class Projectile : public Sprite
{
public:
    Projectile(Vector2 direction, double speed);

private:
    Collision *mp_collision{ nullptr };
    Slot<Collision *> m_collided;
};

//------------------------------------------------------------------//
