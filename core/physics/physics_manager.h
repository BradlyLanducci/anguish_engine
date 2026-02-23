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
    ~PhysicsManager();

    const std::vector<Collision *> &getCollisionObjects();
    void addCollisionObject(Collision *p_collisionObject);
    void addObject(Object *p_object);
    void removeCollisionObject(Object *p_object);
    void removeObject(Object *p_object);
    void update(float currentTime);

    PhysicsManager(const PhysicsManager &) = delete;
    PhysicsManager &operator=(const PhysicsManager &) = delete;

private:
    PhysicsManager() = default;

    static std::vector<Collision *> m_collisionObjects;
    static std::vector<Object *> m_objects;
};

//------------------------------------------------------------------//
