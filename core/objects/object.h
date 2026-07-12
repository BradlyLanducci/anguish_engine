#pragma once

//------------------------------------------------------------------//

#include <objects/item.h>
#include <math/rect.h>
#include <math/transform.h>
#include <utilities/signal.h>

#include <functional>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

/*
    We only want shared objects to be considered for non objects.
    This isn't a design pattern I want to encourage throughout, but
    it's useful for things that are not objects that I'd prefer to
    not have to be managed.
*/
template <typename Type1, typename Type2>
concept not_same_as = !std::same_as<Type1, Type2>;

template <not_same_as<Object> ValueType>
using Shared = std::shared_ptr<ValueType>;

//------------------------------------------------------------------//

struct InputEvent;

//------------------------------------------------------------------//

class Object : public Item
{
    using DeltaUpdateCb = std::function<void(double)>;
    using InputCb = std::function<void(Shared<InputEvent>)>;

public:
    ~Object() override;

    /// @brief All objects allocated on the heap have their memory registered
    /// in the memory manager.
    /// @param size
    /// @return
    static void *operator new(std::size_t size);

    /// @brief Adds an idle frame callback. This is called every frame
    /// by the idle manager.
    /// @param cb
    void addIdleCb(const DeltaUpdateCb &cb);

    /// @brief Adds a physics frame callback. This is called every frame by the physics manager.
    void addPhysicsCb(const DeltaUpdateCb &cb);

    /// @brief Adds an input event callback. This is called every frame by the input manager.
    /// @param cb
    void addInputCb(const InputCb &cb);

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

    /// @brief Returns whether or not this is a UI object.
    /// @return
    [[nodiscard]] bool isUi() const;

    void setTransform(const Transform &transform);
    void setPosition(Vector2 position);
    void setGlobalPosition(Vector2 globalPosition);
    void setRotation(double rotation);
    void setSize(const Vector2 &size);
    void setScale(const Vector2 &scale);
    void setParent(Object *p_parent);
    void setIsUi(bool isUi);

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
    friend class InputManager;

    void idleUpdate(double deltaTime);
    void physicsUpdate(double deltaTime);
    void inputEvent(Shared<InputEvent> event);

    std::vector<DeltaUpdateCb> m_idleCbs;
    std::vector<DeltaUpdateCb> m_physicsCbs;
    std::vector<InputCb> m_inputCbs;

    Object *mp_parent{ nullptr };
    Vector2 m_size;
    Transform m_transform;
    std::vector<Object *> m_children;

    bool m_isUi{ false };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
