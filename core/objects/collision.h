#pragma once

//------------------------------------------------------------------//

#include <objects/sprite.h>
#include <utilities/signal.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class Collision : public Object
{
public:
    Collision(bool debug = false);
    ~Collision() override;

    bool enabled() const;
    bool solid() const;

    void setEnabled(bool enabled);
    void setSolid(bool solid);

    Signal<Collision *> collided;

private:
    Slot<Vector2> m_onResized;

    Sprite *mp_sprite{ nullptr };
    bool m_enabled{ true };
    bool m_solid{ true };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
