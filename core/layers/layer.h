#pragma once

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
