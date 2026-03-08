#pragma once

#include <objects/collision.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
    Character();
    Character(Collision *p_collision);

    Collision *collision() const;
    Vector2 velocity() const;

    void setCollision(Collision *p_collision);
    void setVelocity(const Vector2 &velocity);

private:
    void physicsUpdate(double deltaTime);

    Slot<Vector2> m_resolveCollision;

    Collision *mp_collision{ nullptr };

    Vector2 m_velocity;
};

//------------------------------------------------------------------//
