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
        None,
        Left,
        Middle,
        Right
    };

    static void initialize(GLFWwindow *window);
    static bool isPressed(ButtonType button);

private:
    static void processCursorMove(GLFWwindow *window, double xPos, double yPos);
    static void processCursorEnter(GLFWwindow *window, int entered);
    static void processCursorClick(GLFWwindow *window, int button, int action, int mods);

    static inline ButtonType m_pressedButton;
    static inline Vector2 m_cursorPosition;
    static inline bool m_cursorInWindow{ false };
};

//------------------------------------------------------------------//
