#include <grass_scene/player/projectile.h>

#include <memory/memory_manager.h>

//------------------------------------------------------------------//

Projectile::Projectile(Vector2 direction, double speed)
    : mp_collision(new Collision())
    , m_collided(
          [this](Collision *p_collision)
          {
              if (!dynamic_cast<Projectile *>(p_collision->parent()))
              {
                  MemoryManager::get().queueDelete(this);
              }
          })
{
    addChild(mp_collision);
    addPhysicsCb([this, direction, speed](double deltaTime)
                 { setGlobalPosition(globalPosition() + Vector2(1.0, 0.0) * 200.0 * deltaTime); });
    mp_collision->collided.connect(m_collided);
}

//------------------------------------------------------------------//

void Projectile::setTexture(const std::string &texturePath)
{
    Sprite::setTexture("example/grass_scene/textures/banana.png");
    mp_collision->setSize({ m_texture.size() });
}

//------------------------------------------------------------------//
