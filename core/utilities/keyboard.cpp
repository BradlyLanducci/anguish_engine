#include <utilities/keyboard.h>

#include <utilities/logger.h>
#include <magic_enum/magic_enum.hpp>

// #define LOG_KEYS

//------------------------------------------------------------------//

void Keyboard::initialize(GLFWwindow *window)
{
    glfwSetKeyCallback(window, Keyboard::processInput);
}

//------------------------------------------------------------------//

bool Keyboard::isPressed(Key key)
{
    return m_keyboard[key];
}

//------------------------------------------------------------------//

void Keyboard::processInput(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Key k{ static_cast<Key>(key) };
    if (action == GLFW_PRESS)
    {
        m_keyboard[k] = true;

#ifdef LOG_KEYS
        Log(Info) << key << " : " << " pressed";
#endif
    }
    else if (action == GLFW_RELEASE)
    {
        m_keyboard[k] = false;

#ifdef LOG_KEYS
        Log(Info) << key << " : " << " released";
#endif
    }
}

//------------------------------------------------------------------//
