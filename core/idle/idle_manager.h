#pragma once

//------------------------------------------------------------------//

#include <utilities/object_queue.h>

#include <vector>
#include <memory>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

/// @brief Manages all objects idle time in the engine
class IdleManager
{
public:
    IdleManager(const IdleManager &) = delete;
    IdleManager &operator=(const IdleManager &) = delete;

    static IdleManager &get();

    /// @brief Releases all objects owned by this manager.
    void destroy();

    /// @brief Adds a object at the beginning of the idle frame.
    /// @param p_object
    void addObject(Object *p_object);

    /// @brief Removes a object at the beginning of the idle frame.
    /// @param p_object
    void removeObject(Object *p_object);

    /// @brief Main update function for the idle manager. This will be
    /// called once per game frame.
    /// @param currentTime
    void update(double currentTime);

private:
    IdleManager() = default;

    static inline ObjectQueue<Object *> m_queue;
};

//------------------------------------------------------------------//
