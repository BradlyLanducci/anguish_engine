#pragma once

#include <objects/character.h>
#include <objects/collision.h>
#include <audio/audio_player.h>

//------------------------------------------------------------------//

class Jumper : public Object
{
public:
    Jumper(Character *p_subject, Collision *p_subject_collision);

    enum class State : uint32_t
    {
        Idle,
        Jumping,
        Falling
    } state{ State::Idle };

    void begin(double jumpTime, double jumpForce);

private:
    void physicsUpdate(double delta);

    Character *mp_subject{ nullptr };
    Collision *mp_subjectCollision{ nullptr };
    Slot<bool> m_onFloorChanged;
    AudioPlayer m_jumpSfx;

    double m_accumulator{};
    double m_jumpForce{};
    double m_jumpSeconds{};
};

//------------------------------------------------------------------//
