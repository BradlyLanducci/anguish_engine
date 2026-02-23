#include <objects/collision.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

Collision::Collision()
    : Object(false, false)
{
    PhysicsManager::addCollisionObject(this);
}

//------------------------------------------------------------------//
