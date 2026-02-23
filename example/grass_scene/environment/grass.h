#pragma once

//------------------------------------------------------------------//

#include <objects/collision.h>
#include <objects/sprite.h>

//------------------------------------------------------------------//

class Grass : public Object
{
public:
    Grass();
    ~Grass() override = default;

    void idleUpdate(float delta) override;
    void physicsUpdate(float delta) override;

private:
    Sprite *m_sprite;
    Collision *m_collision;
};

//------------------------------------------------------------------//
