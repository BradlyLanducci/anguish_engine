#include <objects/collision.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

Collision::Collision()
{
    PhysicsManager::get().addCollisionObject(this);
}

//------------------------------------------------------------------//

Collision::~Collision()
{
    PhysicsManager::get().removeCollisionObject(this);
}

//------------------------------------------------------------------//
