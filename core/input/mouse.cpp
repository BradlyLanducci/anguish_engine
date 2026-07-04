#include <input/mouse.h>
#include <input/input_manager.h>
#include <input/input_event.h>

#include <magic_enum/magic_enum.hpp>

//------------------------------------------------------------------//

void Mouse::initialize(GLFWwindow *window)
{
    glfwSetCursorPosCallback(window, Mouse::processCursorMove);
    glfwSetMouseButtonCallback(window, Mouse::processCursorClick);
}

//------------------------------------------------------------------//

bool Mouse::isPressed(ButtonType button)
{
    return m_pressedButton == button;
}

//------------------------------------------------------------------//

void Mouse::processCursorMove(GLFWwindow *window, double xPos, double yPos)
{
    m_cursorPosition = Vector2{ xPos, yPos };

    Shared<MouseMoveEvent> p_event{ std::shared_ptr<MouseMoveEvent>(new MouseMoveEvent()) };

    p_event->position = m_cursorPosition;

    InputManager::get().addEvent(p_event);
}

//------------------------------------------------------------------//

void Mouse::processCursorClick(GLFWwindow *window, int button, int action, int mods)
{
    Shared<MouseClickEvent> p_event{ std::shared_ptr<MouseClickEvent>(new MouseClickEvent()) };

    p_event->position = m_cursorPosition;
    p_event->pressed = (action == GLFW_PRESS);
    p_event->buttonType = static_cast<ButtonType>(button);

    InputManager::get().addEvent(p_event);
}

//------------------------------------------------------------------//
