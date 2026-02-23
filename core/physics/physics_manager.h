#pragma once

//------------------------------------------------------------------//

#include <vector>

//------------------------------------------------------------------//

class Object;
class Collision;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class PhysicsManager
{
public:
    static PhysicsManager &get();
    static const std::vector<Collision *> &getCollisionObjects();
    static void addCollisionObject(Collision *collisionObject);
    static void addObject(Object *object);
    static void update(float currentTime);

    PhysicsManager(const PhysicsManager &) = delete;
    PhysicsManager &operator=(const PhysicsManager &) = delete;

private:
    PhysicsManager() = default;
    ~PhysicsManager() = default;

    static std::vector<Collision *> m_collisionObjects;
    static std::vector<Object *> m_objects;
};

//------------------------------------------------------------------//
