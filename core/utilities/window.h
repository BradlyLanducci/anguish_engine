#pragma once

//------------------------------------------------------------------//

#include <math/vector2i.h>
#include <math/vector2.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

//------------------------------------------------------------------//

constexpr uint32_t DEFAULT_WINDOW_WIDTH{ 960 };
constexpr uint32_t DEFAULT_WINDOW_HEIGHT{ 1280 };

constexpr uint32_t DEFAULT_ASPECT_RATIO_WIDTH{ 3 };
constexpr uint32_t DEFAULT_ASPECT_RATIO_HEIGHT{ 4 };

//------------------------------------------------------------------//

class Window
{
public:
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    /// @brief Returns the main window for this application.
    /// @return
    static GLFWwindow *get();

    /// @brief Returns the applications window size.
    /// @return
    static Vector2 size();

    /// @brief Sets the windows current size
    /// @param size A 2D vector representing the windows new width and height.
    static void setWindowSize(const Vector2i &size);

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
