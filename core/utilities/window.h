#pragma once

//------------------------------------------------------------------//

#include <utilities/vector2.h>

#include <GLFW/glfw3.h>

//------------------------------------------------------------------//

constexpr uint32_t WINDOW_WIDTH{ 1920 };
constexpr uint32_t WINDOW_HEIGHT{ 1080 };

constexpr uint32_t ASPECT_RATIO_WIDTH{ 16 };
constexpr uint32_t ASPECT_RATIO_HEIGHT{ 9 };

//------------------------------------------------------------------//

class Window
{
public:
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    static GLFWwindow *get();
    static Vector2 size();

private:
    Window() = default;
    ~Window();

    static void frameBufferSizeCallback(GLFWwindow *window, int width, int height);

    static void createWindow(uint32_t width, uint32_t height);
    static void destroy();

    static inline GLFWwindow *mp_window{ nullptr };
    static inline Vector2 m_windowSize;
};

//------------------------------------------------------------------//
