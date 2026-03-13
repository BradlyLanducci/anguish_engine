#pragma once

//------------------------------------------------------------------//

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

    /// @brief Adds an idle frame callback. This is called every frame
    /// by the idle manager.
    /// @param cb
    void addIdleCb(const UpdateCb &cb);

    /// @brief Adds an physics frame callback. This is called every frame
    /// by the physics manager.
    void addPhysicsCb(const UpdateCb &cb);

    /// @brief Adds an object to be considered an owned child of this object.
    /// @param p_child The child to add.
    void addChild(Object *p_child);

    /// @brief Removes a child from this object.
    /// @param p_child The child to remove
    void removeChild(Object *p_child);

    /// @brief Returns the rectangle represented by this objects global position and size (Doesn't consider scale).
    /// @return
    Rect rect() const;

    /// @brief Returns the local transform.
    /// @return
    [[nodiscard]] const Transform &transform() const;

    /// @brief Returns the global transform.
    /// @return
    [[nodiscard]] const Transform &globalTransform() const;

    /// @brief Returns the local position.
    /// @return
    [[nodiscard]] const Vector2 &position() const;

    /// @brief Returns the global position.
    /// @return
    [[nodiscard]] Vector2 globalPosition() const;

    /// @brief Returns the global rotation.
    /// @return
    [[nodiscard]] double rotation() const;

    /// @brief Returns the size.
    /// @return
    [[nodiscard]] const Vector2 &size() const;

    /// @brief Returns the global scale.
    /// @return
    [[nodiscard]] Vector2 scale() const;

    /// @brief Returns the parent of this object.
    /// @return
    [[nodiscard]] Object *parent() const;

    void setTransform(const Transform &transform);
    void setPosition(Vector2 position);
    void setGlobalPosition(Vector2 globalPosition);
    void setRotation(double rotation);
    void setSize(const Vector2 &size);
    void setScale(const Vector2 &scale);
    void setParent(Object *p_parent);

    /// @brief Queues this object to be deleted with the memory manager.
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
