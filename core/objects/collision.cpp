#include <objects/collision.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

Collision::Collision(bool debug)
    : mp_sprite(debug ? new Sprite() : nullptr)
    , m_onResized([this](Vector2 newSize) { mp_sprite->setSize(newSize); })
{
    if (mp_sprite)
    {
        addChild(mp_sprite);
        resized.connect(m_onResized);
    }

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
    if (mp_sprite)
    {
        mp_sprite->setEnabled(enabled);
    }
}

//------------------------------------------------------------------//

void Collision::setSolid(bool solid)
{
    m_solid = solid;
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
