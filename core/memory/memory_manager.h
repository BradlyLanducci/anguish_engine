#pragma once

//------------------------------------------------------------------//

#include <vector>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

class MemoryManager
{
public:
    static MemoryManager &get();

    void addItem(Object *p_object);

    void queueDelete(Object *p_object);

    void process();

    MemoryManager(const MemoryManager &) = delete;
    MemoryManager &operator=(const MemoryManager &) = delete;

private:
    MemoryManager() = default;

    static inline std::vector<Object *> m_items;
    static inline std::vector<Object *> m_itemsToDelete;
};

//------------------------------------------------------------------//
