#pragma once

#include <objects/collision.h>

//------------------------------------------------------------------//

class Jumper : public Object
{
public:
    Jumper(Object *p_subject, Collision *p_subject_collision);

    enum class State : uint32_t
    {
        Idle,
        Jumping,
        Falling
    } state{ State::Idle };

    void begin(double jumpTime, double jumpForce);

private:
    void physicsUpdate(double delta);

    Object *mp_subject{ nullptr };
    Collision *mp_subjectCollision{ nullptr };

    Slot<Vector2> m_collided;

    double m_accumulator{};
    double m_jumpForce{};
    double m_jumpSeconds{};
};

//------------------------------------------------------------------//
