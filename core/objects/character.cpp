#include <objects/character.h>

//------------------------------------------------------------------//

Character::Character()
    : Object(true, true)
    , m_resolveCollision([this](Vector2 offset) { setGlobalPosition(globalPosition() + offset); })
{
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
