#include <input/keyboard.h>
#include <input/input_event.h>
#include <utilities/logger.h>

#include <magic_enum/magic_enum.hpp>

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
    bool pressed{ action == GLFW_PRESS || action == GLFW_REPEAT };

    m_keyboard[k] = pressed;

    Shared<KeyboardEvent> p_event{ std::shared_ptr<KeyboardEvent>(new KeyboardEvent()) };
    p_event->key = static_cast<Key>(key);
    p_event->pressed = pressed;
    InputManager::get().addEvent(p_event);
}

//------------------------------------------------------------------//
