#include <grass_scene/environment/grass.h>

//------------------------------------------------------------------//

Grass::Grass()
    : Object()
    , m_sprite(new Sprite())
    , m_collision(new Collision())
{
    addChild(m_sprite);
    addChild(m_collision);
    m_sprite->setTexture("example/grass_scene/textures/grass.png");
    setSize(m_sprite->rect().size);
    m_collision->setSize(size());
    setGlobalPosition(Vector2(0, 600));
}

//------------------------------------------------------------------//

void Grass::idleUpdate(float delta)
{
}

//------------------------------------------------------------------//

void Grass::physicsUpdate(float delta)
{
}

//------------------------------------------------------------------//
