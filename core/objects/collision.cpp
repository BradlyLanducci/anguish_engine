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

bool Collision::enabled() const
{
    return m_enabled;
}

//------------------------------------------------------------------//

bool Collision::solid() const
{
    return m_solid;
}

//------------------------------------------------------------------//

void Collision::setEnabled(bool enabled)
{
    m_enabled = enabled;
}

//------------------------------------------------------------------//

void Collision::setSolid(bool solid)
{
    m_solid = solid;
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
