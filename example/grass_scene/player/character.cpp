#include <grass_scene/player/character.h>
#include <utilities/keyboard.h>
#include <utilities/camera.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

Character::Character()
    : Object(false, true)
    , mp_sprite(new Sprite())
    , mp_collision(new CollisionObject())
    , m_jumper(this, mp_collision)
{
    addChild(mp_sprite);
    addChild(mp_collision);

    mp_sprite->setTexture("example/grass_scene/textures/bananaman.png");
    mp_sprite->setScale({ 0.25, 0.25 });
    mp_collision->setSize(mp_sprite->rect().size * mp_sprite->rect().scale);
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
