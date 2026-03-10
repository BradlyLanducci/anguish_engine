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

PhysicsManager::~PhysicsManager()
{
    for (const auto &p_object : m_collisionObjects)
    {
        Log(Error) << "Leaked physics object " << p_object;
    }
}

//------------------------------------------------------------------//

const std::vector<Collision *> &PhysicsManager::getCollisionObjects()
{
    return m_collisionObjects;
}

//------------------------------------------------------------------//

void PhysicsManager::addCollisionObject(Collision *p_collisionObject)
{
    m_collisionObjectsQueue.push_back(p_collisionObject);
}

//------------------------------------------------------------------//

void PhysicsManager::addObject(Object *p_object)
{
    m_objectsQueue.push_back(p_object);
}

//------------------------------------------------------------------//

void PhysicsManager::removeObject(Object *p_object)
{
    std::erase(m_objects, p_object);
}

//------------------------------------------------------------------//

void PhysicsManager::removeCollisionObject(Object *p_object)
{
    std::erase(m_collisionObjects, p_object);
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
        for (const auto &o : m_objects)
        {
            o->physicsUpdate(PHYSICS_INTERVAL);
        }

        // Collect collisions
        std::vector<std::pair<Collision *, Collision *>> collisions;
        size_t numObjects{ m_collisionObjects.size() };
        for (size_t i = 0; i < numObjects; i++)
        {
            for (size_t j = i + 1; j < numObjects; j++)
            {
                auto co1{ m_collisionObjects[i] };
                auto co2{ m_collisionObjects[j] };
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

        for (const auto &p_object : m_objectsQueue)
        {
            m_objects.push_back(p_object);
        }

        m_objectsQueue.clear();

        for (const auto &p_object : m_collisionObjectsQueue)
        {
            m_collisionObjects.push_back(p_object);
        }

        m_collisionObjectsQueue.clear();

        dtAccumulator -= PHYSICS_INTERVAL;
    }
}

//------------------------------------------------------------------//
