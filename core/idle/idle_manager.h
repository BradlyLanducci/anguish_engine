#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

/// @brief Manages all objects idle time in the engine
class IdleManager
{
public:
    static IdleManager &get();
    ~IdleManager();

    void addObject(Object *p_object);
    void removeObject(Object *p_object);
    void update(float currentTime);

    IdleManager(const IdleManager &) = delete;
    IdleManager &operator=(const IdleManager &) = delete;

private:
    IdleManager() = default;

    static std::vector<Object *> m_objects;
};

//------------------------------------------------------------------//
