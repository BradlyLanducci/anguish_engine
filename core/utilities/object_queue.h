#pragma once

#include <vector>

//------------------------------------------------------------------//

template <typename ObjectType>
class ObjectQueue
{
public:
    /// @brief Queues an object to be deleted on the next update.
    /// @param object The object to delete.
    void remove(ObjectType object)
    {

        m_removeQueue.push_back(object);
    }

    /// @brief Queues an object to be added on the next update.
    /// @param object The object to add.
    void add(ObjectType object)
    {
        m_addQueue.push_back(object);
    }

    /// @brief Updates the main queue by deleting then adding any
    /// queued objects.
    void update()
    {
        for (const auto &object : m_removeQueue)
        {
            std::erase(m_queue, object);
        }

        for (const auto &object : m_addQueue)
        {
            m_queue.push_back(object);
        }

        m_removeQueue.clear();
        m_addQueue.clear();
    }

    void clear()
    {
        m_queue.clear();
        m_addQueue.clear();
        m_removeQueue.clear();
    }

    size_t size() const
    {
        return m_queue.size();
    }

    /// @brief Returns the provided index of the main queue.
    /// @param index
    /// @return
    ObjectType &operator[](size_t index)
    {
        return m_queue[index];
    }

    std::vector<ObjectType>::iterator begin()
    {
        return m_queue.begin();
    }

    std::vector<ObjectType>::iterator end()
    {
        return m_queue.end();
    }

private:
    std::vector<ObjectType> m_queue;
    std::vector<ObjectType> m_addQueue;
    std::vector<ObjectType> m_removeQueue;
};

//------------------------------------------------------------------//
