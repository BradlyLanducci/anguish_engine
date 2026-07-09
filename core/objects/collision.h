#pragma once

//------------------------------------------------------------------//

#include <objects/object.h>
#include <utilities/signal.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class Collision : public Object
{
public:
    Collision();
    ~Collision() override;

    bool solid() const;

    void setSolid(bool solid);

    Signal<Collision *> collided;

private:
    bool m_solid{ true };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
