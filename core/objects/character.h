#pragma once

#include <objects/collision.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
    Character();
    Character(Collision *p_collision);

    Collision *collision() const;

    void setCollision(Collision *p_collision);

private:
    Slot<Vector2> m_resolveCollision;

    Collision *mp_collision{ nullptr };

    Vector2 m_velocity;
};

//------------------------------------------------------------------//
