#pragma once

//------------------------------------------------------------------//

#include <utilities/window.h>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

class Game
{
public:
    Game();
    ~Game();

    /// @brief Runs the main game loop. Each of these loops is considered
    /// a 'Game Frame'.
    /// @return
    int run();

    /// @brief Sets the root object of this game.
    /// @param p_object
    void setRoot(Object *p_object);

private:
    GLFWwindow *mp_window;

    Object *mp_root{ nullptr };
};

//------------------------------------------------------------------//
