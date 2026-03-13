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

void IdleManager::destroy()
{
    m_queue.clear();
}

//------------------------------------------------------------------//

void IdleManager::addObject(Object *p_object)
{
    m_queue.add(p_object);
}

//------------------------------------------------------------------//

void IdleManager::removeObject(Object *p_object)
{
    m_queue.remove(p_object);
}

//------------------------------------------------------------------//

void IdleManager::update(double currentTime)
{
    static double lastTime{ Time::now_s() };

    double deltaTime{ std::clamp(currentTime - lastTime, 0.0, 0.1) };
    lastTime = currentTime;

    m_queue.update();

    for (const auto &p_object : m_queue)
    {
        p_object->idleUpdate(deltaTime);
    }
}

//------------------------------------------------------------------//
