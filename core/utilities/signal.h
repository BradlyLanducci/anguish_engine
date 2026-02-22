#pragma once

#include <functional>
#include <unordered_map>

//------------------------------------------------------------------//

struct Signal
{
    /*
        Ugly temporary solution for the ability to disconnect slots from signals.
    */
    [[nodiscard]] uint32_t connect(const std::function<void()> &slot)
    {
        m_slots.try_emplace(m_handleIndex, slot);

        uint32_t handleIndex{ m_handleIndex };
        m_handleIndex++;
        return handleIndex;
    }

    void disconnect(uint32_t signalHandle)
    {
        m_slots.erase(signalHandle);
    }

    void emit() const
    {
        for (const auto &[_, slot] : m_slots)
        {
            slot();
        }
    }

    void removeConnections()
    {
        m_slots.clear();
    }

private:
    uint32_t m_handleIndex{};
    using Slot = std::function<void()>;
    std::unordered_map<uint32_t, Slot> m_slots;
};

//------------------------------------------------------------------//
