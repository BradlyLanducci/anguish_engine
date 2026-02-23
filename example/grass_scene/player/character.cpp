#include <grass_scene/player/character.h>
#include <utilities/keyboard.h>
#include <utilities/camera_manager.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

Character::Character()
    : Object(false, true)
    , mp_sprite(new Sprite())
    , mp_collision(new Collision())
    , m_jumper(this, mp_collision)
{
    setScale({ 0.25f, 0.25f });

    addChild(mp_sprite);
    addChild(mp_collision);

    mp_sprite->setTexture("example/grass_scene/textures/bananaman.png");

    mp_collision->setSize(mp_sprite->size() * mp_sprite->scale());
}

//------------------------------------------------------------------//

void Character::physicsUpdate(float delta)
{
    Vector2 gp{ globalPosition() };
    if (m_jumper.state != Jumper::State::Jumping)
    {
        float gravity{ 300.f * delta };
        gp.y += gravity;
    }

    float amountToMove{ 200.f * delta };

    if (Keyboard::isPressed(Keyboard::Key::Left))
    {
        gp.x -= amountToMove;
    }
    if (Keyboard::isPressed(Keyboard::Key::Up))
    {
        m_jumper.begin(0.3f, 300.f);
    }
    if (Keyboard::isPressed(Keyboard::Key::Right))
    {
        gp.x += amountToMove;
    }

    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
