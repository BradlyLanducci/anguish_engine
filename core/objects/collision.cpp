#include <objects/collision.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

Collision::Collision()
    : Object(false, false)
{
    PhysicsManager::get().addCollisionObject(this);
}

//------------------------------------------------------------------//

Collision::~Collision()
{
    PhysicsManager::get().removeCollisionObject(this);
}

//------------------------------------------------------------------//
