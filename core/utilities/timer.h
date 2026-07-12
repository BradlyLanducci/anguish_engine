#pragma once

#include <objects/object.h>
#include <utilities/signal.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class Timer : public Object
{
public:
    Timer(double seconds, double oneShot = true);

    bool running() const;

    /// @brief Starts the timer.
    void start();

    /// @brief Stops the timer.
    void stop();

    Signal<> finished;

private:
    void idleUpdate(double deltaTime);

    bool m_running{ false };

    double m_seconds{};
    bool m_oneShot{ false };

    double m_accumulator{};
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
