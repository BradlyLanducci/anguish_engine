#include <input/input_manager.h>
#include <input/mouse.h>
#include <objects/object.h>
#include <utilities/logger.h>
#include <input/input_event.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

InputManager &InputManager::get()
{
    static InputManager i;
    return i;
}

//------------------------------------------------------------------//

void InputManager::destroy()
{
    m_objectsQueue.clear();
}

//------------------------------------------------------------------//

void InputManager::addObject(Object *p_object)
{
    m_objectsQueue.add(p_object);
}

//------------------------------------------------------------------//

void InputManager::removeObject(Object *p_object)
{
    m_objectsQueue.remove(p_object);
}

//------------------------------------------------------------------//

void InputManager::addEvent(Shared<InputEvent> event)
{
    m_events.push_back(event);
}

//------------------------------------------------------------------//

void InputManager::process()
{
    m_objectsQueue.update();

    for (auto &event : m_events)
    {
        for (auto &p_object : m_objectsQueue)
        {
            p_object->inputEvent(event);
        }
    }

    m_events.clear();
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
