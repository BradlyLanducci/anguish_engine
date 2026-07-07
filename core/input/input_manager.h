#pragma once

//------------------------------------------------------------------//

#include <utilities/object_queue.h>
#include <objects/object.h>

#include <vector>

//------------------------------------------------------------------//

class InputEvent;

//------------------------------------------------------------------//

/// @brief Manages all input events in the engine
class InputManager
{
public:
    InputManager(const InputManager &) = delete;
    InputManager &operator=(const InputManager &) = delete;

    static InputManager &get();

    /// @brief Releases all objects owned by this manager.
    void destroy();

    /// @brief Adds a object at the beginning of the current main loop.
    void addObject(Object *p_object);

    /// @brief Removes a object at the beginning of the current main loop.
    void removeObject(Object *p_object);

    /// @brief Adds an event to be processed at the next call of process.
    /// @param event The input event to process.
    void addEvent(Shared<InputEvent> event);

    /// @brief Processes all input events.
    void process();

private:
    InputManager() = default;

    static inline ObjectQueue<Object *> m_objectsQueue;

    /*
        The motivation behind this being a shared pointer is so that this can contain different input event types. I'd
       rather it be a shared ptr than raw.
    */
    static inline std::vector<Shared<InputEvent>> m_events;
};

//------------------------------------------------------------------//
