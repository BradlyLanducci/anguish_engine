#include <grass_scene/player/jumper.h>

//------------------------------------------------------------------//

Jumper::Jumper(Object *p_subject, CollisionObject *p_subject_collision)
    : mp_subject(p_subject)
    , mp_subjectCollision(p_subject_collision)
{
    (void)mp_subjectCollision->collided.connect(
        [this]()
        {
            if (state == State::Falling)
            {
                state = State::Idle;
            }
        });
}

//------------------------------------------------------------------//

void Jumper::begin(float jumpSeconds, float jumpForce)
{
    if (state == State::Idle)
    {
        m_accumulator = 0.f;
        m_jumpSeconds = jumpSeconds;
        m_jumpForce = jumpForce;
        state = State::Jumping;
    }
}

//------------------------------------------------------------------//

void Jumper::physicsUpdate(float delta)
{
    if (state == State::Jumping)
    {
        m_accumulator += delta;

        if (m_accumulator <= m_jumpSeconds)
        {
            float progress{ 1.f - (m_accumulator / m_jumpSeconds) };
            auto gp{ mp_subject->globalPosition() };
            gp.y -= m_jumpForce * delta * progress;
            mp_subject->setGlobalPosition(gp);
        }
        else
        {
            state = State::Falling;
        }
    }
}

//------------------------------------------------------------------//
