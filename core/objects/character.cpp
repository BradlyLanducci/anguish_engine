#include <objects/character.h>

//------------------------------------------------------------------//

Character::Character()
    : m_resolveCollision([this](Vector2 offset) { setGlobalPosition(globalPosition() + offset); })
{
    addPhysicsCb([this](double deltaTime) { physicsUpdate(deltaTime); });
}

//------------------------------------------------------------------//

Character::Character(Collision *p_collision)
    : Character()
{
    setCollision(p_collision);
}

//------------------------------------------------------------------//

Collision *Character::collision() const
{
    return mp_collision;
}

//------------------------------------------------------------------//

void Character::setCollision(Collision *p_collision)
{
    if (mp_collision)
    {
        mp_collision->collided.disconnect(m_resolveCollision);
    }

    mp_collision = p_collision;
    mp_collision->collided.connect(m_resolveCollision);
}

//------------------------------------------------------------------//

void Character::setVelocity(const Vector2 &velocity)
{
    m_velocity = velocity;
}

//------------------------------------------------------------------//

void Character::physicsUpdate(double deltaTime)
{
    setGlobalPosition(globalPosition() + m_velocity * deltaTime);
}

//------------------------------------------------------------------//
