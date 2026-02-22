#include <objects/collision_object.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

CollisionObject::CollisionObject()
    : Object(false, false)
{
    PhysicsManager::addCollisionObject(this);
}

//------------------------------------------------------------------//
