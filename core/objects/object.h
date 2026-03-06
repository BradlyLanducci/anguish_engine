#pragma once

#include <objects/item.h>
#include <utilities/rect.h>
#include <utilities/signal.h>
#include <utilities/transform.h>

#include <functional>

//------------------------------------------------------------------//

class Object : public Item
{
public:
    explicit Object(bool doIdle = true, bool doPhysics = true);
    ~Object() override;

    void addChild(Object *p_child);

    virtual void idleUpdate(float delta);
    virtual void physicsUpdate(float delta);

    [[nodiscard]] const Transform &transform() const;
    [[nodiscard]] const Transform &globalTransform() const;
    [[nodiscard]] const Vector2 &position() const;
    [[nodiscard]] Vector2 globalPosition() const;
    [[nodiscard]] const Vector2 &size() const;
    [[nodiscard]] Vector2 scale() const;
    [[nodiscard]] Object *parent() const;

    void setTransform(const Transform &transform);
    void setPosition(Vector2 position);
    void setGlobalPosition(Vector2 globalPosition);
    void setSize(const Vector2 &size);
    void setScale(const Vector2 &scale);
    void setParent(Object *p_parent);

    Signal moved;
    Signal resized;
    Signal scaled;

private:
    bool m_idleObject{ true };
    bool m_physicsObject{ true };
    Object *mp_parent{ nullptr };
    Vector2 m_size;
    Transform m_transform;
    std::vector<Object *> m_children;
};

//------------------------------------------------------------------//
