#pragma once

//------------------------------------------------------------------//

#include <objects/sprite.h>

#include <objects/collision.h>

//------------------------------------------------------------------//

class Projectile : public Sprite
{
public:
    Projectile(Vector2 direction, double speed);

    void setTexture(const std::string &texturePath) override;

private:
    Collision *mp_collision{ nullptr };
    Slot<Collision *> m_collided;
};

//------------------------------------------------------------------//
