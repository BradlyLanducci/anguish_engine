#include <main_scene/banana_man.h>

#include <input/input_event.h>
#include <input/keyboard.h>
#include <utilities/camera_manager.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

BananaMan::BananaMan(std::array<std::array<int, 14>, 18> &board)
    : AE::Character(new AE::Collision())
    , m_board(board)
    , mp_sprite(new AE::AnimatedSprite())
{
    addPhysicsCb([this](double deltaTimeTime) { physicsUpdate(deltaTimeTime); });

    addChild(mp_sprite);
    addChild(collision());

    const int numFrames{ 1 };
    const int rows{ 1 };
    const int columns{ 1 };
    const int fps{ 1 };
    const bool loops{ true };
    auto walk{ std::make_shared<AE::Spritesheet>("examples/pacman/banana_man.png", numFrames, rows, columns, fps,
                                                 loops) };
    mp_sprite->addAnimation("walk", walk);
    mp_sprite->playAnimation("walk");

    collision()->setSize(mp_sprite->size());
}

//------------------------------------------------------------------//

void BananaMan::physicsUpdate(double deltaTime)
{
    Direction previousDirection{ m_direction };

    handleInput();

    constexpr double PPS{ 32.0 };
    double distance{ deltaTime * PPS };

    AE::Vector2 newPosition{ m_pos };

    if (m_direction == Direction::Up)
    {
        newPosition.y -= distance;
    }
    else if (m_direction == Direction::Down)
    {
        newPosition.y += distance;
    }
    else if (m_direction == Direction::Left)
    {
        newPosition.x -= distance;
    }
    else if (m_direction == Direction::Right)
    {
        newPosition.x += distance;
    }

    AE::Vector2 gp{ newPosition };
    gp.x /= 16.0;
    gp.x = std::floor(gp.x);
    gp.y /= 16.0;
    gp.y = std::floor(gp.y);

    size_t x{ static_cast<size_t>(gp.x) };
    size_t y{ static_cast<size_t>(gp.y) };
    if (m_board[y][x])
    {
        // We should either remove this, or have it calculate the distance for the previous direction instead
        m_direction = previousDirection;
        return;
    }

    // Update player + "ghosts"

    gp.x *= 16.0;
    gp.y *= 16.0;

    m_pos = newPosition;

    mp_sprite->setGlobalPosition(gp);
}

//------------------------------------------------------------------//

void BananaMan::handleInput()
{
    if (AE::Keyboard::isPressed(AE::Keyboard::Key::Up))
    {
        m_direction = Direction::Up;
    }
    else if (AE::Keyboard::isPressed(AE::Keyboard::Key::Down))
    {
        m_direction = Direction::Down;
    }
    else if (AE::Keyboard::isPressed(AE::Keyboard::Key::Left))
    {
        m_direction = Direction::Left;
    }
    else if (AE::Keyboard::isPressed(AE::Keyboard::Key::Right))
    {
        m_direction = Direction::Right;
    }
}

//------------------------------------------------------------------//
