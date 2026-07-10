#include <grass_scene/player/player.h>
#include <grass_scene/player/projectile.h>

#include <input/input_event.h>
#include <input/keyboard.h>
#include <utilities/camera_manager.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

Player::Player()
    : AE::Character(new AE::Collision())
    , mp_sprite(new AE::AnimatedSprite())
    , m_jumper(this, collision())
    , m_shootSfx("examples/platformer/grass_scene/audio/shoot.wav")
{
    addPhysicsCb([this](double deltaTimeTime) { physicsUpdate(deltaTimeTime); });

    setScale({ 0.125, 0.125 });

    addChild(mp_sprite);
    addChild(collision());

    auto idle{ std::make_shared<AE::Spritesheet>("examples/platformer/grass_scene/textures/idle.png", 1, 1, 1, 1,
                                                 true) };

    const int numFrames{ 24 };
    const int rows{ 4 };
    const int columns{ 6 };
    const int fps{ 8 };
    const bool loops{ false };
    auto walkLeft{ std::make_shared<AE::Spritesheet>("examples/platformer/grass_scene/textures/walk_left.png",
                                                     numFrames, rows, columns, fps, loops) };
    auto walkRight{ std::make_shared<AE::Spritesheet>("examples/platformer/grass_scene/textures/walk_right.png",
                                                      numFrames, rows, columns, fps, loops) };
    mp_sprite->addAnimation("idle", idle);
    mp_sprite->addAnimation("walkLeft", walkLeft);
    mp_sprite->addAnimation("walkRight", walkRight);

    collision()->setSize(AE::Vector2(150, 175));

    addInputCb(
        [this](AE::Shared<AE::InputEvent> event)
        {
            AE::Shared<AE::MouseClickEvent> p_clickEvent{ AE::InputEvent::GetType<AE::MouseClickEvent>(event) };

            if (p_clickEvent)
            {
                bool isLeftClick{ p_clickEvent->buttonType == AE::Mouse::ButtonType::Left };
                bool isPressed{ p_clickEvent->pressed };

                if (isLeftClick && isPressed)
                {
                    shoot();
                }
            }
        });
}

//------------------------------------------------------------------//

Json::Value Player::serialize()
{
    Json::Value root;
    root["globalPosition"] = globalPosition().toJson();
    return root;
}

//------------------------------------------------------------------//

void Player::deserialize(const Json::Value &data)
{
    auto gp{ data.get("globalPosition", Json::Value()) };
    double x{ gp.get("x", 0.0).asDouble() };
    double y{ gp.get("y", 0.0).asDouble() };
    setGlobalPosition({ x, y });
}

//------------------------------------------------------------------//

void Player::physicsUpdate(double deltaTime)
{
    AE::Vector2 gp{ globalPosition() };
    if (m_jumper.state != Jumper::State::Jumping)
    {
        double gravity{ 300.0 * (double)deltaTime };
        gp.y += gravity;
    }

    handleInput();

    setGlobalPosition(gp);
}

//------------------------------------------------------------------//

void Player::handleInput()
{
    constexpr double amountToMove{ 200.0 };

    if (AE::Keyboard::isPressed(AE::Keyboard::Key::Left))
    {
        mp_sprite->playAnimation("walkLeft");
        setVelocity({ -amountToMove, 0.0 });
        m_facingRight = false;
    }
    else if (AE::Keyboard::isPressed(AE::Keyboard::Key::Right))
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

    if (AE::Keyboard::isPressed(AE::Keyboard::Key::Enter) && !m_shooting)
    {
        shoot();
    }
    else if (!AE::Keyboard::isPressed(AE::Keyboard::Key::Enter))
    {
        m_shooting = false;
    }

    if (AE::Keyboard::isPressed(AE::Keyboard::Key::Up))
    {
        m_jumper.begin(0.3, 2000.0);
    }
}

//------------------------------------------------------------------//

void Player::shoot()
{
    if (!m_shooting)
    {
        m_shootSfx.play();
        m_shooting = true;
        auto p_parent{ parent() };
        if (p_parent)
        {
            AE::Vector2 direction{ m_facingRight ? AE::Vector2(1.0, 0.0) : AE::Vector2(-1.0, 0.0) };
            double speed{ 1000.0 };
            Projectile *p_projectile{ new Projectile(direction, speed) };
            AE::Vector2 initialPosition{ globalPosition() + (m_facingRight ? AE::Vector2(200, 0) : AE::Vector2()) };
            p_projectile->setGlobalPosition(initialPosition);
            p_parent->addChild(p_projectile);
        }
    }
}

//------------------------------------------------------------------//
