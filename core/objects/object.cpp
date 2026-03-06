#include <objects/object.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

Object::Object(bool doIdle, bool doPhysics)
    : m_idleObject(doIdle)
    , m_physicsObject(doPhysics)
{
    if (doIdle)
    {
        IdleManager::get().addObject(this);
    }

    if (doPhysics)
    {
        PhysicsManager::get().addObject(this);
    }
}

//------------------------------------------------------------------//

Object::~Object()
{
    for (auto &c : m_children)
    {
        if (c)
        {
            delete c;
            c = nullptr;
        }
    }

    m_children.clear();

    if (m_idleObject)
    {
        IdleManager::get().removeObject(this);
    }

    if (m_physicsObject)
    {
        PhysicsManager::get().removeObject(this);
    }
}

//------------------------------------------------------------------//

void Object::addChild(Object *p_child)
{
    p_child->setParent(this);
    m_children.push_back(p_child);
}

//------------------------------------------------------------------//

void Object::setParent(Object *p_parent)
{
    mp_parent = p_parent;
}

//------------------------------------------------------------------//

Object *Object::getParent() const
{
    return mp_parent;
}

//------------------------------------------------------------------//

void Object::idleUpdate(float delta)
{
}

//------------------------------------------------------------------//

void Object::physicsUpdate(float delta)
{
}

//------------------------------------------------------------------//

Rect Object::rect() const
{
    return m_rect;
}

//------------------------------------------------------------------//

Rect Object::globalRect() const
{
    return Rect{ globalPosition(), size(), scale() };
}

//------------------------------------------------------------------//

Vector2 Object::position() const
{
    return m_rect.origin;
}

//------------------------------------------------------------------//

Vector2 Object::globalPosition() const
{
    Vector2 gp{ m_rect.origin };

    auto p_parent{ mp_parent };
    while (p_parent)
    {
        gp += p_parent->rect().origin;
        p_parent = p_parent->getParent();
    }

    return gp;
}

//------------------------------------------------------------------//

Vector2 Object::size() const
{
    return m_rect.size;
}

//------------------------------------------------------------------//

Vector2 Object::scale() const
{
    Vector2 scale{ m_scale };

    auto p_parent{ mp_parent };
    while (p_parent)
    {
        scale *= p_parent->m_scale;
        p_parent = p_parent->getParent();
    }

    return scale;
}

//------------------------------------------------------------------//

Object *Object::parent() const
{
    return mp_parent;
}

//------------------------------------------------------------------//

void Object::setRect(const Rect &rect)
{
    m_rect = rect;

    moved.emit();
    resized.emit();
    scaled.emit();
}

//------------------------------------------------------------------//

void Object::setPosition(Vector2 position)
{
    m_rect.origin = position;
    moved.emit();
}

//------------------------------------------------------------------//

void Object::setGlobalPosition(Vector2 globalPosition)
{
    m_rect.origin = globalPosition;
    moved.emit();
}

//------------------------------------------------------------------//

void Object::setSize(const Vector2 &size)
{
    m_rect.size = size;
    resized.emit();
}

//------------------------------------------------------------------//

void Object::setScale(const Vector2 &scale)
{
    m_scale = scale;
    scaled.emit();
}

//------------------------------------------------------------------//
