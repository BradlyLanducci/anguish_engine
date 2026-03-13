#pragma once

//------------------------------------------------------------------//

#include <vector>

//------------------------------------------------------------------//

class Layer;
class Object;

//------------------------------------------------------------------//

class MemoryManager
{
public:
    MemoryManager(const MemoryManager &) = delete;
    MemoryManager &operator=(const MemoryManager &) = delete;

    static MemoryManager &get();

    void destroy();

    void process();

private:
    MemoryManager() = default;

    friend Object;

    /// @brief Queues an object to be deleted at the beginning of the next
    /// game frame.
    /// @param p_object
    void queueDelete(Object *p_object);

    /// @brief Adds an item to be managed by the the memory manager.
    /// @param p_object
    void addItem(Object *p_object);

    /*
        We don't use an object queue here because it requires more
        specific logic for deleting objects
    */

    static inline std::vector<Object *> m_items;
    static inline std::vector<Object *> m_itemsToDelete;
};

//------------------------------------------------------------------//
