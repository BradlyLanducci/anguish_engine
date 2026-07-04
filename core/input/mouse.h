#pragma once

//------------------------------------------------------------------//

#include <math/vector2.h>

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <atomic>

//------------------------------------------------------------------//

class Mouse
{
public:
    enum class ButtonType : uint32_t
    {
        None = 8, // Outside range of GLFW buttons
        Left = GLFW_MOUSE_BUTTON_LEFT,
        Middle = GLFW_MOUSE_BUTTON_MIDDLE,
        Right = GLFW_MOUSE_BUTTON_RIGHT
    };

    static void initialize(GLFWwindow *window);
    static bool isPressed(ButtonType button);

private:
    static void processCursorMove(GLFWwindow *window, double xPos, double yPos);
    static void processCursorClick(GLFWwindow *window, int button, int action, int mods);

    static inline ButtonType m_pressedButton;
    static inline Vector2 m_cursorPosition;
};

//------------------------------------------------------------------//
