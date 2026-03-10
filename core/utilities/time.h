#pragma once

//------------------------------------------------------------------//

#include <chrono>

//------------------------------------------------------------------//

class Time
{
public:
    static uint64_t now_ns()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch())
            .count();
    }

    static uint64_t now_ms()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now().time_since_epoch())
            .count();
    }

    static double now_s()
    {
        double ns{ static_cast<double>(now_ns()) };
        return ns / 1'000'000'000.0;
    }

private:
    Time();
};

//------------------------------------------------------------------//
