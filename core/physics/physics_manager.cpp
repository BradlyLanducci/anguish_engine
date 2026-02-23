#include <physics/physics_manager.h>
#include <objects/collision.h>
#include <physics/aabb.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

constexpr float PHYSICS_INTERVAL = 1.f / 60.f;

//------------------------------------------------------------------//

std::vector<Object *> PhysicsManager::m_objects;
std::vector<Collision *> PhysicsManager::m_collisionObjects;

//------------------------------------------------------------------//

PhysicsManager &PhysicsManager::get()
{
    static PhysicsManager p;
    return p;
}

//------------------------------------------------------------------//

const std::vector<Collision *> &PhysicsManager::getCollisionObjects()
{
    return m_collisionObjects;
}

//------------------------------------------------------------------//

void PhysicsManager::addCollisionObject(Collision *collisionObject)
{
    m_collisionObjects.push_back(collisionObject);
    Log(Info) << "Added collision object now we have " << m_collisionObjects.size() << " objects";
}

//------------------------------------------------------------------//

void PhysicsManager::addObject(Object *object)
{
    m_objects.push_back(object);
    Log(Info) << "Added object " << object << " now we have " << m_objects.size() << " objects";
}

//------------------------------------------------------------------//

void PhysicsManager::update(float currentTime)
{
    static float lastTime{};
    static float dtAccumulator{};

    float deltaTime{ currentTime - lastTime };
    lastTime = currentTime;

    dtAccumulator += deltaTime;

    /*
        We want to calculate all possible physics frames that we have available.
    */
    while (dtAccumulator >= PHYSICS_INTERVAL)
    {
        // Call physics update
        for (const auto &o : m_objects)
        {
            o->physicsUpdate(PHYSICS_INTERVAL);
        }

        // Collect collisions
        std::vector<std::pair<Collision *, Collision *>> collisions;
        for (const auto &co1 : m_collisionObjects)
        {
            for (const auto &co2 : m_collisionObjects)
            {
                if (co1 != co2)
                {
                    Rect r1{ co1->globalRect() };
                    Rect r2{ co2->globalRect() };

                    if (AABB::aabb(r1, r2))
                    {
                        /// TODO: This seems really inefficient lol
                        bool duplicate = false;
                        for (const auto &collision : collisions)
                        {
                            if (collision.first == co1 && collision.second == co2)
                            {
                                duplicate = true;
                            }
                            else if (collision.second == co1 && collision.first == co2)
                            {
                                duplicate = true;
                            }
                        }
                        if (!duplicate)
                        {
                            collisions.push_back(std::pair(co1, co2));
                        }
                    }
                }
            }
        }

        for (auto &collision : collisions)
        {
            Collision *co1{ collision.first };
            Collision *co2{ collision.second };

            Rect r1{ co1->globalRect() };
            Rect r2{ co2->globalRect() };

            Vector2 offset{ AABB::collide(r1, r2) };
            Object *parent{ co1->getParent() };
            co1->collided.emit();
            if (parent)
            {
                Vector2 offsetPos{ co1->globalPosition() + offset };
                Vector2 roundedPos{ Vector2(std::round(offsetPos.x), std::round(offsetPos.y)) };
                parent->setGlobalPosition(roundedPos);
            }
        }

        dtAccumulator -= PHYSICS_INTERVAL;
    }
}

//------------------------------------------------------------------//
