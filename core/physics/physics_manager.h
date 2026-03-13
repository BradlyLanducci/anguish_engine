#pragma once

//------------------------------------------------------------------//

#include <utilities/object_queue.h>

#include <vector>

//------------------------------------------------------------------//

class Game;
class Object;
class Collision;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class PhysicsManager
{
public:
    static PhysicsManager &get();

    /// @brief Releases all objects owned by this manager.
    void destroy();

    /// @brief Adds a collision object at the beginning of the physics frame.
    /// @param p_collisionObject
    void addCollisionObject(Collision *p_collisionObject);

    /// @brief Adds a object at the beginning of the physics frame.
    void addObject(Object *p_object);

    /// @brief Removes a collision object at the beginning of the physics frame.
    void removeCollisionObject(Collision *p_object);

    /// @brief Removes a object at the beginning of the physics frame.
    void removeObject(Object *p_object);

    PhysicsManager(const PhysicsManager &) = delete;
    PhysicsManager &operator=(const PhysicsManager &) = delete;

private:
    PhysicsManager() = default;

    friend Game;

    /// @brief Main update function for the physics manager. This will call however
    /// many physics frames need to be called per game frame based on the internal
    /// time accumulator.
    /// @param currentTime
    void update(double currentTime);

    static inline ObjectQueue<Collision *> m_collisionQueue;
    static inline ObjectQueue<Object *> m_objectsQueue;
};

//------------------------------------------------------------------//
