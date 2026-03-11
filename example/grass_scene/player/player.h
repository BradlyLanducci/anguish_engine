#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/character.h>
#include <objects/animated_sprite.h>
#include <audio/audio_player.h>

//------------------------------------------------------------------//

class Player : public Character
{
public:
    Player();

private:
    void physicsUpdate(double deltaTime);
    AnimatedSprite *mp_sprite;
    Jumper m_jumper;
    AudioPlayer m_shootSfx;

    bool m_facingRight{ true };

    bool m_enterPressed{ false };
};

//------------------------------------------------------------------//
