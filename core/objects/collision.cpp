#include <objects/collision.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

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

END_AE_NAMESPACE

//------------------------------------------------------------------//
