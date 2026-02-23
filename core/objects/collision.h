#pragma once

#include <objects/object.h>
#include <utilities/signal.h>

//------------------------------------------------------------------//

class Collision : public Object
{
public:
    Collision();
    ~Collision() override;

    Signal collided;
};

//------------------------------------------------------------------//