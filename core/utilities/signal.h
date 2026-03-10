#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <functional>

//------------------------------------------------------------------//

/*
    Modified from https://medium.com/brakulla/signal-slot-implementation-part-1-adb458454f05
*/

template <typename... Args>
class Slot
{
public:
    Slot(const Slot &) = delete;
    Slot(Slot &&) = delete;
    Slot &operator=(const Slot &) = delete;

    explicit Slot(std::function<void(Args...)> cb)
        : m_cb(cb)
    {
    }

    void operator()(Args... args)
    {
        call(args...);
    }

    void call(Args... args)
    {
        m_cb(args...);
    }

private:
    bool m_initiated{ false };
    std::function<void(Args...)> m_cb;
};

//------------------------------------------------------------------//

template <typename... Args>
class Signal
{
public:
    Signal(const Signal &) = delete;
    Signal(Signal &&) = delete;
    Signal &operator=(const Signal &) = delete;

    Signal() = default;

    void connect(Slot<Args...> &slot)
    {
        m_slots.push_back(&slot);
    }

    void disconnect(Slot<Args...> &slot)
    {
        for (auto it = m_slots.begin(); it != m_slots.end();)
        {
            if (*it == &slot)
            {
                it = m_slots.erase(it);
            }
            else
            {
                it++;
            }
        }
    }

    void disconnectAll()
    {
        m_slots.clear();
    }

    void emit(Args... args)
    {
        for (auto &slot : m_slots)
        {
            (*slot)(args...);
        }
    }

    size_t numConnections() const
    {
        return m_slots.size();
    }

private:
    std::vector<Slot<Args...> *> m_slots;
};

//------------------------------------------------------------------//
