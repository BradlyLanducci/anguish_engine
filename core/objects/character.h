#pragma once

#include <objects/collision.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
    Character();
    Character(Collision *p_collision);

    bool isOnFloor() const;

    Collision *collision() const;
    Vector2 velocity() const;

    void setCollision(Collision *p_collision);
    void setVelocity(const Vector2 &velocity);

    Signal<bool> onFloorChanged;

private:
    void setIsOnFloor(bool isOnFloor);
    void physicsUpdate(double deltaTime);

    Slot<Collision *> m_resolveCollision;

    Collision *mp_collision{ nullptr };

    Vector2 m_velocity;

    bool m_isOnFloor{ false };
};

//------------------------------------------------------------------//
