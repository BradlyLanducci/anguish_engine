#pragma once

//------------------------------------------------------------------//

#include <grass_scene/player/jumper.h>

#include <objects/character.h>
#include <objects/animated_sprite.h>

//------------------------------------------------------------------//

class Player : public Character
{
public:
    Player();
    ~Player() override = default;

    void physicsUpdate(double delta) override;

private:
    AnimatedSprite *mp_sprite;
    Jumper m_jumper;
};

//------------------------------------------------------------------//
