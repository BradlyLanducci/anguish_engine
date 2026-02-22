#include <grass_scene/player/character.h>
#include <utilities/keyboard.h>
#include <utilities/camera.h>

#include <glog/logging.h>

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
    if (Keyboard::isPressed(263)) // left
    {
        gp.x -= amountToMove;
    }
    if (Keyboard::isPressed(265)) // up
    {
        m_jumper.begin(0.3f, 300.f);
    }
    if (Keyboard::isPressed(262)) // right
    {
        gp.x += amountToMove;
    }
    if (Keyboard::isPressed(264)) // down
    {
        gp.y += amountToMove;
    }

    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
