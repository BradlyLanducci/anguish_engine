#include <utilities/window.h>
#include <math/vector2.h>
#include <input/keyboard.h>
#include <input/mouse.h>

#include <cstdint>
#include <cassert>

//------------------------------------------------------------------//

Window::~Window()
{
    destroy();
}

//------------------------------------------------------------------//

void Window::frameBufferSizeCallback(GLFWwindow *p_window, int width, int height)
{
    (void)p_window;
    glViewport(0, 0, width, height);
    m_windowSize = Vector2{ static_cast<double>(width), static_cast<double>(height) };
}

//------------------------------------------------------------------//

void Window::createWindow(const Vector2i &size)
{
    assert(glfwInit());

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mp_window =
        glfwCreateWindow(static_cast<int>(size.x), static_cast<int>(size.y), "Anguish Engine", nullptr, nullptr);
    assert(mp_window);

    glfwMakeContextCurrent(mp_window);
    assert(gladLoadGL(reinterpret_cast<GLADloadfunc>(glfwGetProcAddress)));

    glfwSetFramebufferSizeCallback(mp_window, frameBufferSizeCallback);

    glfwSetWindowAspectRatio(mp_window, DEFAULT_ASPECT_RATIO_WIDTH, DEFAULT_ASPECT_RATIO_HEIGHT);

    Keyboard::initialize(mp_window);
    Mouse::initialize(mp_window);

    m_windowSize = size;
}

//------------------------------------------------------------------//

void Window::destroy()
{
    glfwTerminate();
}

//------------------------------------------------------------------//

Vector2 Window::size()
{
    return m_windowSize;
}

//------------------------------------------------------------------//

void Window::setAspectRatio(const Vector2i &aspectRatio)
{
    m_aspectRatio = aspectRatio;
    glfwSetWindowAspectRatio(mp_window, aspectRatio.x, aspectRatio.y);
}

//------------------------------------------------------------------//

void Window::setWindowSize(const Vector2i &size)
{
    m_windowSize = Vector2{ static_cast<double>(size.x), static_cast<double>(size.y) };
    glfwSetWindowSize(mp_window, size.x, size.y);
}

//------------------------------------------------------------------//

GLFWwindow *Window::get()
{
    createWindow(Vector2i{ DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT });
    return mp_window;
}

//------------------------------------------------------------------//

Vector2 Window::aspectRatio()
{
    return m_aspectRatio;
}

//------------------------------------------------------------------//
