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

    Signal<Collision *> collided;
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
