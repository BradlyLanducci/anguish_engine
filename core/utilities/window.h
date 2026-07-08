#pragma once

//------------------------------------------------------------------//

#include <math/vector2i.h>
#include <math/vector2.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

constexpr int DEFAULT_WINDOW_WIDTH{ 1920 };
constexpr int DEFAULT_WINDOW_HEIGHT{ 1080 };

constexpr int DEFAULT_ASPECT_RATIO_WIDTH{ 16 };
constexpr int DEFAULT_ASPECT_RATIO_HEIGHT{ 9 };

//------------------------------------------------------------------//

/// @brief The current state of this project expects there to be only one window.
class Window
{
public:
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    /// @brief Returns the main window for this application.
    /// @return
    static GLFWwindow *get();

    static Vector2 aspectRatio();

    /// @brief Returns the applications window size.
    /// @return
    static Vector2 size();

    /// @brief Sets the windows current aspect ratio.
    /// @param aspectRatio A 2D vector representing the windows new x/y aspect ratio.
    static void setAspectRatio(const Vector2i &aspectRatio);

    /// @brief Sets the windows current size.
    /// @param size A 2D vector representing the windows new width and height.
    static void setWindowSize(const Vector2i &size);

private:
    Window() = default;
    ~Window();

    static void frameBufferSizeCallback(GLFWwindow *window, int width, int height);

    static void createWindow(const Vector2i &size);
    static void destroy();

    static inline GLFWwindow *mp_window{ nullptr };
    static inline Vector2 m_windowSize;
    static inline Vector2 m_aspectRatio;
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
