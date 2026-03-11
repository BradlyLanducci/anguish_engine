#include <grass_scene/player/jumper.h>
#include <physics/aabb.h>

//------------------------------------------------------------------//

Jumper::Jumper(Character *p_subject, Collision *p_subject_collision)
    : mp_subject(p_subject)
    , mp_subjectCollision(p_subject_collision)
    , m_onFloorChanged(
          [this](bool isOnFloor)
          {
              if (state == State::Falling)
              {
                  state = State::Idle;
              }
          })
    , m_jumpSfx("example/grass_scene/audio/jump.wav")
{
    mp_subject->isOnFloorChanged.connect(m_onFloorChanged);

    addPhysicsCb([this](double deltaTime) { physicsUpdate(deltaTime); });
}

//------------------------------------------------------------------//

void Jumper::begin(double jumpSeconds, double jumpForce)
{
    if (state == State::Idle)
    {
        m_jumpSfx.play();

        m_accumulator = 0.0;
        m_jumpSeconds = jumpSeconds;
        m_jumpForce = jumpForce;
        state = State::Jumping;
    }
}

//------------------------------------------------------------------//

void Jumper::physicsUpdate(double delta)
{
    if (state == State::Jumping)
    {
        m_accumulator += delta;

        if (m_accumulator <= m_jumpSeconds)
        {
            double progress{ 1.0 - (m_accumulator / m_jumpSeconds) };
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
