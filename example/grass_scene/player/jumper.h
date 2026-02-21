#pragma once

#include <objects/collision_object.h>

//------------------------------------------------------------------//

class Jumper : public Object
{
public:
    Jumper(Object *p_subject, CollisionObject *p_subject_collision);

    enum class State : uint32_t
    {
        Idle,
        Jumping,
        Falling
    } state;

    void begin(float jumpTime, float jumpForce);
    void end();

private:
    void physicsUpdate(float delta);

    Object *mp_subject{ nullptr };
    CollisionObject *mp_subjectCollision{ nullptr };

    float m_accumulator{};
    float m_jumpForce{};
    float m_jumpSeconds{};
};

//------------------------------------------------------------------//
