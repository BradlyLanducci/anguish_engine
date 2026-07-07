#pragma once

//------------------------------------------------------------------//

#include <objects/character.h>
#include <objects/animated_sprite.h>
#include <audio/audio_player.h>

//------------------------------------------------------------------//

class BananaMan : public AE::Character
{
public:
    BananaMan(std::array<std::array<int, 14>, 18> &board);

private:
    void physicsUpdate(double deltaTime);
    void handleInput();

    enum class Direction : int
    {
        Up,
        Down,
        Left,
        Right
    } m_direction{ Direction::Right };

    std::array<std::array<int, 14>, 18> &m_board;

    AE::AnimatedSprite *mp_sprite;
    AE::Vector2 m_pos;
};

//------------------------------------------------------------------//
