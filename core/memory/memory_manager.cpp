#include <memory/memory_manager.h>
#include <objects/object.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

MemoryManager &MemoryManager::get()
{
    static MemoryManager m;
    return m;
}

//------------------------------------------------------------------//

void MemoryManager::addItem(Object *p_object)
{
    m_items.push_back(p_object);
}

//------------------------------------------------------------------//

void MemoryManager::queueDelete(Object *p_object)
{
    for (auto p : m_itemsToDelete)
    {
        if (p == p_object)
        {
            return;
        }
    }

    m_itemsToDelete.push_back(p_object);
}

//------------------------------------------------------------------//

void MemoryManager::process()
{
    for (const auto &toDelete : m_itemsToDelete)
    {
        auto toDeleteIt{ std::find(m_items.begin(), m_items.end(), toDelete) };
        if (toDeleteIt != m_items.end())
        {
            Object *p_parent{ toDelete->parent() };
            if (p_parent)
            {
                p_parent->removeChild(toDelete);
            }
            std::erase(m_items, toDelete);
            delete toDelete;
        }
    }
    m_itemsToDelete.clear();
}

//------------------------------------------------------------------//
