#include <grass_scene/player/character.h>
#include <utilities/keyboard.h>
#include <utilities/camera.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

Character::Character()
    : mp_sprite(new Sprite())
    , mp_collision(new CollisionObject())
    , m_jumper(this, mp_collision)
{
    addChild(mp_sprite);
    addChild(mp_collision);

    mp_sprite->setTexture("example/grass_scene/textures/test.png");
    mp_collision->setSize(mp_sprite->rect().size);

    addIdleCb([this](float delta) { idleUpdate(delta); });
    addPhysicsCb([this](float delta) { physicsUpdate(delta); });
}

//------------------------------------------------------------------//

void Character::idleUpdate(float delta)
{
}

//------------------------------------------------------------------//

void Character::physicsUpdate(float delta)
{
    if (m_jumper.state != Jumper::State::Jumping)
    {
        float gravity = 300.f * delta;
        m_rect.origin.y += gravity;
    }

    float amountToMove = 200.f * delta;

    Vector2 gp = globalPosition();
    if (Keyboard::isPressed(263)) // left
    {
        gp.x -= amountToMove;
    }
    if (Keyboard::isPressed(265)) // up
    {
        m_jumper.begin(0.125, 300.f);
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

    Camera::get().setGlobalPosition(gp);
}

//------------------------------------------------------------------//
