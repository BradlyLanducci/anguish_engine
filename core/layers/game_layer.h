#pragma once

//------------------------------------------------------------------//

#include <utilities/window.h>
#include <layers/layer.h>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

/// @brief This class brings in all managers. You can go off the rails and make your own "GameLayer", but using this as
/// a template is ideal. For example, if you're making pacman you may not want a physics server, so you can validate
/// moves via some "board".
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
