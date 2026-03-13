#pragma once

//------------------------------------------------------------------//

#include <utilities/window.h>
#include <layers/layer.h>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

class GameLayer : public Layer
{
public:
    GameLayer() = default;

    /// @brief Creates a game layer with a root object.
    /// @param p_object The root of the game layer.
    GameLayer(Object *p_object);

    ~GameLayer();

    void destroy() override;

    void update(double deltaTime) override;
    void render() override;

    /// @brief Sets the root object of this game.
    /// @param p_object
    void setRoot(Object *p_object);

private:
    Object *mp_root{ nullptr };
};

//------------------------------------------------------------------//
