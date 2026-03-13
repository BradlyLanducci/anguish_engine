#include <physics/physics_manager.h>
#include <objects/collision.h>
#include <physics/aabb.h>
#include <utilities/time.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

constexpr double PHYSICS_INTERVAL{ 1.0 / 60.0 };

//------------------------------------------------------------------//

PhysicsManager &PhysicsManager::get()
{
    static PhysicsManager p;
    return p;
}

//------------------------------------------------------------------//

void PhysicsManager::destroy()
{
    m_objectsQueue.clear();
    m_collisionQueue.clear();
}

//------------------------------------------------------------------//

void PhysicsManager::addCollisionObject(Collision *p_collisionObject)
{
    m_collisionQueue.add(p_collisionObject);
}

//------------------------------------------------------------------//

void PhysicsManager::addObject(Object *p_object)
{
    m_objectsQueue.add(p_object);
}

//------------------------------------------------------------------//

void PhysicsManager::removeCollisionObject(Collision *p_object)
{
    m_collisionQueue.remove(p_object);
}

//------------------------------------------------------------------//

void PhysicsManager::removeObject(Object *p_object)
{
    m_objectsQueue.remove(p_object);
}

//------------------------------------------------------------------//

void PhysicsManager::update(double currentTime)
{
    static double lastTime{ static_cast<double>(Time::now_s()) };
    static double dtAccumulator{};

    double deltaTime{ currentTime - lastTime };
    lastTime = currentTime;

    dtAccumulator += deltaTime;

    /*
        We want to calculate all possible physics frames that we have available.
    */
    while (dtAccumulator >= PHYSICS_INTERVAL)
    {
        m_objectsQueue.update();
        m_collisionQueue.update();

        for (const auto &o : m_objectsQueue)
        {
            o->physicsUpdate(PHYSICS_INTERVAL);
        }

        // Collect collisions
        std::vector<std::pair<Collision *, Collision *>> collisions;
        size_t numObjects{ m_collisionQueue.size() };
        for (size_t i = 0; i < numObjects; i++)
        {
            for (size_t j = i + 1; j < numObjects; j++)
            {
                auto co1{ m_collisionQueue[i] };
                auto co2{ m_collisionQueue[j] };
                if (co1 != co2)
                {
                    auto collisionIt{ std::find_if(collisions.begin(), collisions.end(), [&co1, &co2](auto collision)
                                                   { return collision.first == co1 && collision.second == co2; }) };
                    if (collisionIt == collisions.end())
                    {
                        Rect r1{ co1->globalPosition(), co1->size() };
                        Rect r2{ co2->globalPosition(), co2->size() };

                        if (AABB::aabb(r1, r2))
                        {
                            collisions.push_back(std::pair(co1, co2));
                        }
                    }
                }
            }
        }

        for (auto &[co1, co2] : collisions)
        {
            co1->collided.emit(co2);
            co2->collided.emit(co1);
        }

        dtAccumulator -= PHYSICS_INTERVAL;
    }
}

//------------------------------------------------------------------//
