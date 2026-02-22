#include <utilities/window.h>
#include <utilities/data_structures.h>
#include <utilities/keyboard.h>

#include <cstdint>
#include <cassert>
#include <glad/glad.h>

//------------------------------------------------------------------//

Window::~Window()
{
    destroy();
}

//------------------------------------------------------------------//

void Window::frameBufferSizeCallback(GLFWwindow *_window, int width, int height)
{
    (void)_window;
    glViewport(0, 0, width, height);
    m_windowSize.x = static_cast<float>(width);
    m_windowSize.y = static_cast<float>(height);
}

//------------------------------------------------------------------//

void Window::createWindow(uint32_t width, uint32_t height)
{
    assert(glfwInit());

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mp_window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), "Anguish Engine", nullptr, nullptr);
    assert(mp_window);

    glfwMakeContextCurrent(mp_window);

    assert(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)));

    glfwSetFramebufferSizeCallback(mp_window, frameBufferSizeCallback);

    glfwSetWindowAspectRatio(mp_window, ASPECT_RATIO_WIDTH, ASPECT_RATIO_HEIGHT);

    Keyboard::initialize(mp_window);

    m_windowSize = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
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

GLFWwindow *Window::get()
{
    createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    return mp_window;
}

//------------------------------------------------------------------//
