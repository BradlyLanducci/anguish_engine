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

    void begin(float jumpTime, float jumpForce);

private:
    void physicsUpdate(float delta);

    Object *mp_subject{ nullptr };
    Collision *mp_subjectCollision{ nullptr };

    float m_accumulator{};
    float m_jumpForce{};
    float m_jumpSeconds{};
};

//------------------------------------------------------------------//
