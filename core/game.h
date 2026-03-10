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

    int run();
    void setRoot(Object *p_object);

private:
    GLFWwindow *mp_window;

    Object *mp_root{ nullptr };
};

//------------------------------------------------------------------//
