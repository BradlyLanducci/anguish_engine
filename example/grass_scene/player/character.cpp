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

    mp_sprite->setTexture("example/grass_scene/textures/test.png");
    mp_collision->setSize(mp_sprite->rect().size);
}

//------------------------------------------------------------------//

void Character::physicsUpdate(float delta)
{
    if (m_jumper.state != Jumper::State::Jumping)
    {
        float gravity{ 300.f * delta };
        m_globalPosition.y += gravity;
    }

    float amountToMove{ 200.f * delta };

    Vector2 gp{ globalPosition() };
    if (Keyboard::isPressed(Keyboard::Key::Left)) // left
    {
        gp.x -= amountToMove;
    }
    if (Keyboard::isPressed(Keyboard::Key::Up)) // up
    {
        m_jumper.begin(0.3f, 300.f);
    }
    if (Keyboard::isPressed(Keyboard::Key::Right)) // right
    {
        gp.x += amountToMove;
    }
    if (Keyboard::isPressed(Keyboard::Key::Down)) // down
    {
        gp.y += amountToMove;
    }

    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
