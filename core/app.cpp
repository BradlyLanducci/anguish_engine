#include <app.h>
#include <utilities/time.h>
#include <utilities/logger.h>
#include <layers/layer.h>

#include <glad/gl.h>

//------------------------------------------------------------------//

App::App()
    : mp_window(Window::get())
{
}

//------------------------------------------------------------------//

int App::run()
{
    if (!mp_window)
    {
        Log(Info) << "Failed to start application window.";
        return -1;
    }

    while (!glfwWindowShouldClose(mp_window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double currentTime = static_cast<double>(Time::now_s());

        for (auto &layer : m_layers)
        {
            layer->update(currentTime);
        }

        for (auto &layer : m_layers)
        {
            layer->render();
        }

        glfwSwapBuffers(mp_window);
        glfwPollEvents();
    }

    for (auto &layer : m_layers)
    {
        layer->destroy();
    }

    return 0;
}

//------------------------------------------------------------------//
