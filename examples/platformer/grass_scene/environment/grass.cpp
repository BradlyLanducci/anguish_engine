#include <grass_scene/environment/grass.h>

//------------------------------------------------------------------//

Grass::Grass()
    : Object()
    , m_sprite(new AE::Sprite())
    , m_collision(new AE::Collision())
{
    addChild(m_sprite);
    addChild(m_collision);
    m_sprite->setTexture("examples/platformer/grass_scene/textures/grass.png");
    setSize(m_sprite->size());
    m_collision->setSize(size());
}

//------------------------------------------------------------------//
