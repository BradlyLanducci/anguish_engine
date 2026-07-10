#include <app.h>
#include <utilities/time.h>
#include <utilities/logger.h>
#include <layers/layer.h>

#include <glad/gl.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

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

    /*
        TODO: From my understanding an optimization would be to enable it only for all transparent objects. Then
        disable it for non transparent for performance reasons.
    */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(mp_window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double currentTime{ static_cast<double>(Time::now_s()) };

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

END_AE_NAMESPACE

//------------------------------------------------------------------//
