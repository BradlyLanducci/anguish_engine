#include <idle/idle_manager.h>
#include <objects/object.h>
#include <utilities/time.h>
#include <utilities/logger.h>

#include <algorithm>

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
    static double lastTime{ Time::now_s() };

    double deltaTime{ std::clamp(currentTime - lastTime, 0.0, 0.1) };
    lastTime = currentTime;
    for (const auto &o : m_objects)
    {
        o->idleUpdate(deltaTime);
    }
}

//------------------------------------------------------------------//
