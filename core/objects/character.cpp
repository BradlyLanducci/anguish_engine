#include <objects/character.h>
#include <physics/aabb.h>

//------------------------------------------------------------------//

Character::Character()
    : m_resolveCollision(
          [this](Collision *p_collision)
          {
              Rect r1{ mp_collision->rect() };
              Rect r2{ p_collision->rect() };
              Vector2 offset{ AABB::collide(r1, r2) };

              bool resolveHorizontal{ offset.x > offset.y };

              if (resolveHorizontal)
              {
                  offset.y = 0.0;
              }
              else
              {
                  offset.x = 0.0;
              }

              setGlobalPosition(globalPosition() + offset);
              if (offset.y != 0.0)
              {
                  setIsOnFloor(true);
              }
          })
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

bool Character::isOnFloor() const
{
    return m_isOnFloor;
}

//------------------------------------------------------------------//

Collision *Character::collision() const
{
    return mp_collision;
}

//------------------------------------------------------------------//

Vector2 Character::velocity() const
{
    return m_velocity;
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

void Character::setIsOnFloor(bool isOnFloor)
{
    m_isOnFloor = isOnFloor;
    isOnFloorChanged.emit(isOnFloor);
}

//------------------------------------------------------------------//

void Character::physicsUpdate(double deltaTime)
{
    setGlobalPosition(globalPosition() + m_velocity * deltaTime);

    if (m_velocity.y > 0.0)
    {
        setIsOnFloor(false);
    }
}

//------------------------------------------------------------------//
