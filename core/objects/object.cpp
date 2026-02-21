#include <objects/object.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

Object::Object(bool doIdle, bool doPhysics)
{
    if (doIdle)
    {
        IdleManager::addObject(this);
    }

    if (doPhysics)
    {
        PhysicsManager::addObject(this);
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
}

//------------------------------------------------------------------//

void Object::addChild(Object *p_child)
{
    p_child->setParent(this);
    m_children.push_back(p_child);
}

//------------------------------------------------------------------//

void Object::addIdleCb(const std::function<void(float)> &cb)
{
    m_idleCbs.push_back(cb);
}

//------------------------------------------------------------------//

void Object::addPhysicsCb(const std::function<void(float)> &cb)
{
    m_physicsCbs.push_back(cb);
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
    for (const auto &cb : m_idleCbs)
    {
        cb(delta);
    }
}

//------------------------------------------------------------------//

void Object::physicsUpdate(float delta)
{
    for (const auto &cb : m_physicsCbs)
    {
        cb(delta);
    }
}

//------------------------------------------------------------------//

Rect Object::rect() const
{
    return m_rect;
}

//------------------------------------------------------------------//

Vector2 Object::position() const
{
    Vector2 gp{ globalPosition() };
    if (mp_parent)
    {
        return mp_parent->globalPosition() - gp;
    }
    return gp;
}

//------------------------------------------------------------------//

Vector2 Object::globalPosition() const
{
    return m_rect.origin;
}

//------------------------------------------------------------------//

Vector2 Object::size() const
{
    return m_rect.size;
}

//------------------------------------------------------------------//

Vector2 Object::scale() const
{
    return m_rect.scale;
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

void Object::setGlobalPosition(Vector2 globalPosition)
{
    globalPosition.roundToInt();
    m_rect.origin = globalPosition;
    for (auto &c : m_children)
    {
        c->setGlobalPosition(globalPosition);
    }

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
    m_rect.scale = scale;
    scaled.emit();
}

//------------------------------------------------------------------//
