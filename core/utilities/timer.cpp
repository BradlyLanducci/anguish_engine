#include <utilities/timer.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

Timer::Timer(double seconds, double oneShot)
{
    m_seconds = seconds;
    m_oneShot = oneShot;
}

//------------------------------------------------------------------//

bool Timer::running() const
{
    return m_running;
}

//------------------------------------------------------------------//

void Timer::start()
{
    m_accumulator = 0.0;
    m_running = true;
}

//------------------------------------------------------------------//

void Timer::stop()
{
    m_accumulator = 0.0;
    m_running = false;
}

//------------------------------------------------------------------//

void Timer::idleUpdate(double deltaTime)
{
    if (m_running)
    {
        m_accumulator += deltaTime;

        if (m_accumulator >= m_seconds)
        {
            m_accumulator = 0.0;
            finished.emit();
        }
    }
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
