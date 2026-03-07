#include <idle/idle_manager.h>
#include <objects/object.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

std::vector<Object *> IdleManager::m_objects;

//------------------------------------------------------------------//

IdleManager &IdleManager::get()
{
    static IdleManager p;
    return p;
}

//------------------------------------------------------------------//

IdleManager::~IdleManager()
{
    for (const auto &p_object : m_objects)
    {
        Log(Error) << "Leaked idle object " << p_object;
    }
}

//------------------------------------------------------------------//

void IdleManager::addObject(Object *p_object)
{
    m_objects.push_back(p_object);
}

//------------------------------------------------------------------//

void IdleManager::removeObject(Object *p_object)
{
    std::erase(m_objects, p_object);
}

//------------------------------------------------------------------//

void IdleManager::update(double currentTime)
{
    static double lastTime = 0.f;

    const double delta{ currentTime - lastTime };
    lastTime = currentTime;
    for (const auto &o : m_objects)
    {
        o->idleUpdate(delta);
    }
}

//------------------------------------------------------------------//
