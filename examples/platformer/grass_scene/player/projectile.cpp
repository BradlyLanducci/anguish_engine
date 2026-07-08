#include <grass_scene/player/projectile.h>
#include <grass_scene/enemies/cabbage_boy.h>
#include <grass_scene/player/player.h>

#include <utilities/type_checking.h>
#include <memory/memory_manager.h>

//------------------------------------------------------------------//

Projectile::Projectile(AE::Vector2 direction, double speed)
    : mp_collision(new AE::Collision())
    , m_collided(
          [this](AE::Collision *p_collision)
          {
              AE::Object *mp_parent{ p_collision->parent() };
              bool isPlayer{ AE::TypeChecking::isType<Player *>(mp_parent) };

              if (isPlayer)
              {
                  return;
              }

              bool isProjectile{ AE::TypeChecking::isType<Projectile *>(mp_parent) };

              if (!isProjectile)
              {
                  bool isCabbageBoy{ AE::TypeChecking::isType<CabbageBoy *>(mp_parent) };
                  if (isCabbageBoy)
                  {
                      p_collision->parent()->queueDelete();
                  }

                  queueDelete();
              }
          })
{
    mp_collision->setSolid(false);
    addChild(mp_collision);
    addPhysicsCb([this, direction, speed](double deltaTime)
                 { setGlobalPosition(globalPosition() + direction * speed * deltaTime); });
    mp_collision->collided.connect(m_collided);

    setTexture("examples/platformer/grass_scene/textures/banana.png");
    mp_collision->setSize({ m_texture.size() });
}

//------------------------------------------------------------------//
