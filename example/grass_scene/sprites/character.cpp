#include <grass_scene/sprites/character.h>
#include <utilities/keyboard.h>
#include <utilities/camera.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

Character::Character()
    : m_sprite(new Sprite())
    , m_collision(new CollisionObject())
{
    addChild(m_sprite);
    addChild(m_collision);

    m_sprite->setTexture("example/grass_scene/textures/test.png");
    m_collision->setSize(m_sprite->rect().size);

    m_collision->collided.connect([this]() { endJump(); });

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
    // Apply gravity
    float gravity = 300 * delta;
    if (m_isJumping)
    {
        m_jumpAccumulator += delta;
        if (m_jumpAccumulator >= m_jumpSeconds / 2.f)
        {
            m_applyGravity = true;
        }

        if (!m_applyGravity)
        {
            gravity *= -1.f;
        }
    }
    m_rect.origin.y += gravity;

    float amountToMove = 200.f * delta;

    Vector2 gp = globalPosition();
    if (Keyboard::isPressed(263)) // left
    {
        gp.x -= amountToMove;
    }
    if (Keyboard::isPressed(265) && m_jumpPressed < 2) // up
    {
        m_jumpPressed++;
        startJump();
    }
    else if (!Keyboard::isPressed(265))
    {
        m_jumpPressed = 0;
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

void Character::startJump()
{
    if (!m_isJumping)
    {
        m_applyGravity = false;
        m_isJumping = true;
        m_jumpAccumulator = 0.f;
    }
}

//------------------------------------------------------------------//

void Character::endJump()
{
    if (m_jumpAccumulator > m_jumpSeconds)
    {
        m_isJumping = false;
        m_applyGravity = true;
    }
}

//------------------------------------------------------------------//
