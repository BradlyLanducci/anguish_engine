#include <grass_scene/player/player.h>
#include <grass_scene/player/projectile.h>

#include <utilities/keyboard.h>
#include <utilities/camera_manager.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

Player::Player()
    : Character(new Collision())
    , mp_sprite(new AnimatedSprite())
    , m_jumper(this, collision())
    , m_shootSfx("example/grass_scene/audio/shoot.wav")
{
    addPhysicsCb([this](double deltaTimeTime) { physicsUpdate(deltaTimeTime); });

    setScale({ 0.125, 0.125 });

    addChild(mp_sprite);
    addChild(collision());

    Shared<Spritesheet> idle{ std::make_shared<Spritesheet>("example/grass_scene/textures/idle.png", 1, 1, 1, 1,
                                                            true) };

    const uint32_t numFrames{ 24 };
    const uint32_t rows{ 4 };
    const uint32_t columns{ 6 };
    const uint32_t fps{ 8 };
    const bool loops{ false };
    Shared<Spritesheet> walkLeft{ std::make_shared<Spritesheet>("example/grass_scene/textures/walk_left.png", numFrames,
                                                                rows, columns, fps, loops) };
    Shared<Spritesheet> walkRight{ std::make_shared<Spritesheet>("example/grass_scene/textures/walk_right.png",
                                                                 numFrames, rows, columns, fps, loops) };
    mp_sprite->addAnimation("idle", idle);
    mp_sprite->addAnimation("walkLeft", walkLeft);
    mp_sprite->addAnimation("walkRight", walkRight);

    collision()->setSize(Vector2(150, 175));
}

//------------------------------------------------------------------//

void Player::physicsUpdate(double deltaTime)
{
    Vector2 gp{ globalPosition() };
    if (m_jumper.state != Jumper::State::Jumping)
    {
        double gravity{ 300.0 * (double)deltaTime };
        gp.y += gravity;
    }

    double amountToMove{ 200.0 };

    if (Keyboard::isPressed(Keyboard::Key::Left))
    {
        mp_sprite->playAnimation("walkLeft");
        setVelocity({ -amountToMove, 0.0 });
        m_facingRight = false;
    }
    else if (Keyboard::isPressed(Keyboard::Key::Right))
    {
        mp_sprite->playAnimation("walkRight");
        setVelocity({ amountToMove, 0.0 });
        m_facingRight = true;
    }
    else
    {
        mp_sprite->playAnimation("idle");
        setVelocity({ 0.0, 0.0 });
    }

    if (Keyboard::isPressed(Keyboard::Key::Enter) && !m_enterPressed)
    {
        m_shootSfx.play();
        m_enterPressed = true;
        auto p_parent{ parent() };
        if (p_parent)
        {
            Vector2 direction{ m_facingRight ? Vector2(1.0, 0.0) : Vector2(-1.0, 0.0) };
            double speed{ 1000.0 };
            Projectile *p_projectile{ new Projectile(direction, speed) };
            Vector2 initialPosition{ globalPosition() + (m_facingRight ? Vector2(200, 0) : Vector2()) };
            p_projectile->setGlobalPosition(initialPosition);
            p_parent->addChild(p_projectile);
        }
    }
    else if (!Keyboard::isPressed(Keyboard::Key::Enter))
    {
        m_enterPressed = false;
    }

    if (Keyboard::isPressed(Keyboard::Key::Up))
    {
        m_jumper.begin(0.3, 300.0);
    }

    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
