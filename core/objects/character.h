#pragma once

//------------------------------------------------------------------//

#include <objects/collision.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
    Character();
    Character(Collision *p_collision);

    /// @brief Returns whether or not the character is on the floor.
    /// This is checked by seeing if there is currently a non zero
    /// y velocity.
    /// @return
    bool isOnFloor() const;

    /// @brief Returns the collision object associated with this character.
    /// @return
    Collision *collision() const;

    Vector2 velocity() const;

    void setCollision(Collision *p_collision);
    void setVelocity(const Vector2 &velocity);

    Signal<bool> isOnFloorChanged;

private:
    void setIsOnFloor(bool isOnFloor);
    void physicsUpdate(double deltaTime);

    Slot<Collision *> m_resolveCollision;

    Collision *mp_collision{ nullptr };

    Vector2 m_velocity;

    bool m_isOnFloor{ false };
};

//------------------------------------------------------------------//
