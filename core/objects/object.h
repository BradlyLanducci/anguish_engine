#pragma once

#include <objects/item.h>
#include <utilities/data_structures.h>
#include <utilities/signal.h>

#include <functional>

//------------------------------------------------------------------//

class Object : public Item
{
public:
    explicit Object(bool doIdle = true, bool doPhysics = true);
    ~Object() override;

    void addChild(Object *p_child);
    [[nodiscard]] Object *getParent() const;

    virtual void idleUpdate(float delta);
    virtual void physicsUpdate(float delta);

    [[nodiscard]] Rect rect() const;
    [[nodiscard]] Vector2 position() const;
    [[nodiscard]] Vector2 globalPosition() const;
    [[nodiscard]] Vector2 size() const;
    [[nodiscard]] Vector2 scale() const;

    void setRect(const Rect &rect);
    void setGlobalPosition(Vector2 globalPosition);
    void setSize(const Vector2 &size);
    void setScale(const Vector2 &scale);

    Signal moved;
    Signal resized;
    Signal scaled;

protected:
    void addIdleCb(const std::function<void(float)> &cb);
    void addPhysicsCb(const std::function<void(float)> &cb);
    void setParent(Object *p_parent);

    Object *mp_parent{ nullptr };
    Rect m_rect;

private:
    std::vector<Object *> m_children;
    std::vector<std::function<void(float)>> m_idleCbs;
    std::vector<std::function<void(float)>> m_physicsCbs;
};

//------------------------------------------------------------------//
