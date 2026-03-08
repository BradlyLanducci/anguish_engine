#include <grass_scene/player/character.h>
#include <utilities/keyboard.h>
#include <utilities/camera_manager.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

Character::Character()
    : Object(false, true)
    , mp_sprite(new AnimatedSprite())
    , mp_collision(new Collision())
    , m_jumper(this, mp_collision)
{
    /// TODO: The scaling of animated spritesheets is effected by the dimensions of the spritesheet
    /// so for example in this case there's 2 frames so the x needs to be half of the y to avoid stretching
    setScale({ 0.0625f, 0.125f });

    addChild(mp_sprite);
    addChild(mp_collision);

    mp_sprite->setTexture("example/grass_scene/textures/bananaman_anim-Sheet.png");

    mp_collision->setSize(mp_sprite->size() * mp_sprite->scale());
}

//------------------------------------------------------------------//

void Character::physicsUpdate(double delta)
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
        gp.x -= amountToMove;
    }
    if (Keyboard::isPressed(Keyboard::Key::Up))
    {
        m_jumper.begin(0.3, 300.0);
    }
    if (Keyboard::isPressed(Keyboard::Key::Right))
    {
        gp.x += amountToMove;
    }

    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
