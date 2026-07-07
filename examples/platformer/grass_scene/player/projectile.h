#pragma once

//------------------------------------------------------------------//

#include <objects/sprite.h>

#include <objects/collision.h>

//------------------------------------------------------------------//

class Projectile : public AE::Sprite
{
public:
    Projectile(AE::Vector2 direction, double speed);

private:
    AE::Collision *mp_collision{ nullptr };
    AE::Slot<AE::Collision *> m_collided;
};

//------------------------------------------------------------------//
