#pragma once

#include <objects/character.h>
#include <objects/collision.h>
#include <audio/audio_player.h>

//------------------------------------------------------------------//

class Jumper : public AE::Object
{
public:
    Jumper(AE::Character *p_subject, AE::Collision *p_subject_collision);

    enum class State : int
    {
        Idle,
        Jumping,
        Falling
    } state{ State::Idle };

    void begin(double jumpTime, double jumpForce);

private:
    void physicsUpdate(double delta);

    AE::Character *mp_subject{ nullptr };
    AE::Collision *mp_subjectCollision{ nullptr };
    AE::Slot<bool> m_onFloorChanged;
    AE::AudioPlayer m_jumpSfx;

    double m_accumulator{};
    double m_jumpForce{};
    double m_jumpSeconds{};
};

//------------------------------------------------------------------//
