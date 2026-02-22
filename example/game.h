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
    void setScene(Scene *s);

private:
    GLFWwindow *mp_window;

    Scene *m_scene{ nullptr };
};

//------------------------------------------------------------------//
