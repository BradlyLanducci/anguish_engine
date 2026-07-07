#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/character.h>
#include <objects/animated_sprite.h>
#include <audio/audio_player.h>

//------------------------------------------------------------------//

class Player : public AE::Character
{
public:
    Player();

private:
    void physicsUpdate(double deltaTime);

    void handleInput();
    void shoot();

    AE::AnimatedSprite *mp_sprite;
    Jumper m_jumper;
    AE::AudioPlayer m_shootSfx;

    bool m_facingRight{ true };

    bool m_shooting{ false };
};

//------------------------------------------------------------------//
