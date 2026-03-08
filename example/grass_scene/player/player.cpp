#include <grass_scene/player/player.h>
#include <utilities/keyboard.h>
#include <utilities/camera_manager.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

Player::Player()
    : Character(new Collision())
    , mp_sprite(new AnimatedSprite())
    , m_jumper(this, collision())
{
    /// TODO: The scaling of animated spritesheets is effected by the dimensions of the spritesheet
    /// so for example in this case there's 2 frames so the x needs to be half of the y to avoid stretching
    setScale({ 0.0625f, 0.125 });

    addChild(mp_sprite);
    addChild(collision());

    const uint32_t numFrames{ 24 };
    const uint32_t rows{ 4 };
    const uint32_t columns{ 6 };
    const uint32_t fps{ 8 };
    const bool loops{ false };

    Shared<Spritesheet> walkLeft{ std::make_shared<Spritesheet>("example/grass_scene/textures/walk_left.png", numFrames,
                                                                rows, columns, fps, loops) };
    Shared<Spritesheet> walkRight{ std::make_shared<Spritesheet>("example/grass_scene/textures/walk_right.png",
                                                                 numFrames, rows, columns, fps, loops) };
    mp_sprite->addAnimation("walkLeft", walkLeft);
    mp_sprite->addAnimation("walkRight", walkRight);

    collision()->setSize(mp_sprite->size() * mp_sprite->scale());
}

//------------------------------------------------------------------//

void Player::physicsUpdate(double delta)
{
    Vector2 gp{ globalPosition() };
    if (m_jumper.state != Jumper::State::Jumping)
    {
        double gravity{ 300.0 * (double)delta };
        gp.y += gravity;
    }

    double amountToMove{ 200.0 * (double)delta };

    if (Keyboard::isPressed(Keyboard::Key::Left))
    {
        mp_sprite->playAnimation("walkLeft");
        gp.x -= amountToMove;
    }
    if (Keyboard::isPressed(Keyboard::Key::Up))
    {
        m_jumper.begin(0.3, 300.0);
    }
    if (Keyboard::isPressed(Keyboard::Key::Right))
    {
        mp_sprite->playAnimation("walkRight");
        gp.x += amountToMove;
    }

    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
