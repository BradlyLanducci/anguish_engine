#include <objects/object.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>
#include <memory/memory_manager.h>
#include <utilities/logger.h>

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

    if (m_idleCbs.size() > 0)
    {
        IdleManager::get().removeObject(this);
    }

    if (m_physicsCbs.size() > 0)
    {
        PhysicsManager::get().removeObject(this);
    }
}

//------------------------------------------------------------------//

void *Object::operator new(std::size_t size)
{
    void *p{ std::malloc(size) };
    if (!p)
    {
        throw std::bad_alloc();
    }

    MemoryManager::get().addItem(static_cast<Object *>(p));

    return p;
}

//------------------------------------------------------------------//

void Object::addIdleCb(const UpdateCb &cb)
{
    if (m_idleCbs.size() == 0)
    {
        IdleManager::get().addObject(this);
    }
    m_idleCbs.push_back(cb);
}

//------------------------------------------------------------------//

void Object::addPhysicsCb(const UpdateCb &cb)
{
    if (m_idleCbs.size() == 0)
    {
        PhysicsManager::get().addObject(this);
    }
    m_physicsCbs.push_back(cb);
}

//------------------------------------------------------------------//

void Object::addChild(Object *p_child)
{
    p_child->setParent(this);
    m_children.push_back(p_child);
}

//------------------------------------------------------------------//

void Object::removeChild(Object *p_child)
{
    std::erase(m_children, p_child);
}

//------------------------------------------------------------------//

void Object::setParent(Object *p_parent)
{
    mp_parent = p_parent;
}

//------------------------------------------------------------------//

void Object::queueDelete()
{
    MemoryManager::get().queueDelete(this);
}

//------------------------------------------------------------------//

void Object::idleUpdate(double deltaTime)
{
    for (const auto &cb : m_idleCbs)
    {
        cb(deltaTime);
    }
}

//------------------------------------------------------------------//

void Object::physicsUpdate(double deltaTime)
{
    for (const auto &cb : m_physicsCbs)
    {
        cb(deltaTime);
    }
}

//------------------------------------------------------------------//

Rect Object::rect() const
{
    return { globalPosition(), size() };
}

//------------------------------------------------------------------//

const Transform &Object::transform() const
{
    return m_transform;
}

//------------------------------------------------------------------//

const Transform &Object::globalTransform() const
{
    return m_transform;
}

//------------------------------------------------------------------//

const Vector2 &Object::position() const
{
    return m_transform.position;
}

//------------------------------------------------------------------//

Vector2 Object::globalPosition() const
{
    Vector2 gp{ m_transform.position };

    auto p_parent{ parent() };
    while (p_parent)
    {
        gp += p_parent->m_transform.position;
        p_parent = p_parent->parent();
    }

    return gp;
}

//------------------------------------------------------------------//

double Object::rotation() const
{
    double rot{ m_transform.rotation };

    auto p_parent{ parent() };
    while (p_parent)
    {
        rot += p_parent->m_transform.rotation;
        p_parent = p_parent->parent();
    }

    return rot;
}

//------------------------------------------------------------------//

Vector2 Object::scale() const
{
    Vector2 scale{ m_transform.scale };

    auto p_parent{ parent() };
    while (p_parent)
    {
        scale *= p_parent->m_transform.scale;
        p_parent = p_parent->parent();
    }

    return scale;
}

//------------------------------------------------------------------//

const Vector2 &Object::size() const
{
    return m_size;
}

//------------------------------------------------------------------//

Object *Object::parent() const
{
    return mp_parent;
}

//------------------------------------------------------------------//

void Object::setTransform(const Transform &transform)
{
    m_transform = transform;

    moved.emit(transform.position);
    scaled.emit(transform.scale);
}

//------------------------------------------------------------------//

void Object::setPosition(Vector2 position)
{
    m_transform.position = position;
    moved.emit(position);
}

//------------------------------------------------------------------//

void Object::setGlobalPosition(Vector2 globalPosition)
{
    m_transform.position = globalPosition;
    moved.emit(globalPosition);
}

//------------------------------------------------------------------//

void Object::setRotation(double rotation)
{
    m_transform.rotation = rotation;
    rotated.emit(rotation);
}

//------------------------------------------------------------------//

void Object::setScale(const Vector2 &scale)
{
    m_transform.scale = scale;
    scaled.emit(scale);
}

//------------------------------------------------------------------//

void Object::setSize(const Vector2 &size)
{
    m_size = size;
    resized.emit(size);
}

//------------------------------------------------------------------//
