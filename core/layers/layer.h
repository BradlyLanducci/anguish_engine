#pragma once

#include <ae_core.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class Event;

//------------------------------------------------------------------//

class Layer
{
public:
    virtual ~Layer() = default;

    virtual void destroy();

    /// @brief
    /// @param deltaTime
    virtual void update(double deltaTime);

    /// @brief
    virtual void render();
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
