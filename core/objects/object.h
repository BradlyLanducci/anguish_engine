#pragma once

#include <objects/item.h>
#include <math/rect.h>
#include <utilities/signal.h>
#include <math/transform.h>

#include <functional>

//------------------------------------------------------------------//

class Object : public Item
{
    using UpdateCb = std::function<void(double)>;

public:
    ~Object() override;

    static void *operator new(std::size_t size);

    void addIdleCb(const UpdateCb &cb);
    void addPhysicsCb(const UpdateCb &cb);
    void addChild(Object *p_child);

    void removeChild(Object *p_child);

    Rect rect() const;
    [[nodiscard]] const Transform &transform() const;
    [[nodiscard]] const Transform &globalTransform() const;
    [[nodiscard]] const Vector2 &position() const;
    [[nodiscard]] Vector2 globalPosition() const;
    [[nodiscard]] double rotation() const;
    [[nodiscard]] const Vector2 &size() const;
    [[nodiscard]] Vector2 scale() const;
    [[nodiscard]] Object *parent() const;

    void setTransform(const Transform &transform);
    void setPosition(Vector2 position);
    void setGlobalPosition(Vector2 globalPosition);
    void setRotation(double rotation);
    void setSize(const Vector2 &size);
    void setScale(const Vector2 &scale);
    void setParent(Object *p_parent);

    void queueDelete();

    Signal<Vector2> moved;
    Signal<Vector2> resized;
    Signal<double> rotated;
    Signal<Vector2> scaled;

private:
    /// TODO: I wonder if it's reasonable to have these just be signals/slots from the managers themselves?
    /// It seems a little jank, but it would be more conistent maybe.
    friend class PhysicsManager;
    friend class IdleManager;
    void idleUpdate(double deltaTime);
    void physicsUpdate(double deltaTime);

    std::vector<UpdateCb> m_idleCbs;
    std::vector<UpdateCb> m_physicsCbs;

    Object *mp_parent{ nullptr };
    Vector2 m_size;
    Transform m_transform;
    std::vector<Object *> m_children;
};

//------------------------------------------------------------------//
