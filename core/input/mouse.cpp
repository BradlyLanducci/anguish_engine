#include <input/mouse.h>
#include <input/input_manager.h>
#include <input/input_event.h>

#include <magic_enum/magic_enum.hpp>

//------------------------------------------------------------------//

void Mouse::initialize(GLFWwindow *window)
{
    glfwSetCursorPosCallback(window, Mouse::processCursorMove);
    glfwSetCursorEnterCallback(window, Mouse::processCursorEnter);
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

    InputManager::get().addEvent(std::shared_ptr<MouseInputEvent>(new MouseInputEvent{
        .position = Vector2{ xPos, yPos },
          .pressed = false
    }));
}

//------------------------------------------------------------------//

void Mouse::processCursorEnter(GLFWwindow *window, int entered)
{
    m_cursorInWindow = (entered == GLFW_TRUE) ? true : false;
}

//------------------------------------------------------------------//

void Mouse::processCursorClick(GLFWwindow *window, int button, int action, int mods)
{
    // Send event
}

//------------------------------------------------------------------//
