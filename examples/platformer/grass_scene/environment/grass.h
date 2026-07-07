#pragma once

//------------------------------------------------------------------//

#include <objects/collision.h>
#include <objects/sprite.h>

//------------------------------------------------------------------//

class Grass : public AE::Object
{
public:
    Grass();
    ~Grass() override = default;

private:
    AE::Sprite *m_sprite;
    AE::Collision *m_collision;
};

//------------------------------------------------------------------//
