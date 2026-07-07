#include <grass_scene/player/projectile.h>
#include <grass_scene/enemies/cabbage_boy.h>

#include <memory/memory_manager.h>

//------------------------------------------------------------------//

Projectile::Projectile(AE::Vector2 direction, double speed)
    : mp_collision(new AE::Collision())
    , m_collided(
          [this](AE::Collision *p_collision)
          {
              if (!dynamic_cast<Projectile *>(p_collision->parent()))
              {
                  if (dynamic_cast<CabbageBoy *>(p_collision->parent()))
                  {
                      p_collision->parent()->queueDelete();
                  }

                  queueDelete();
              }
          })
{
    addChild(mp_collision);
    addPhysicsCb([this, direction, speed](double deltaTime)
                 { setGlobalPosition(globalPosition() + direction * speed * deltaTime); });
    mp_collision->collided.connect(m_collided);

    setTexture("examples/platformer/grass_scene/textures/banana.png");
    mp_collision->setSize({ m_texture.size() });
}

//------------------------------------------------------------------//
