#pragma once

#include <utilities/window.h>

//------------------------------------------------------------------//

class Scene;

//------------------------------------------------------------------//

class Game
{
public:
    Game();
    ~Game();

    int run();
    void setScene(Scene *p_scene);

private:
    GLFWwindow *mp_window;

    Scene *mp_scene{ nullptr };
};

//------------------------------------------------------------------//
