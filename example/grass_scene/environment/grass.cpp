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
    setSize(m_sprite->size());
    m_collision->setSize(size());
}

//------------------------------------------------------------------//

void Grass::idleUpdate(double delta)
{
}

//------------------------------------------------------------------//

void Grass::physicsUpdate(double delta)
{
}

//------------------------------------------------------------------//
