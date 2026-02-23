#include <game.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>
#include <renderer/rendering_manager.h>
#include <scenes/scene.h>

#include <utilities/logger.h>
#include <glad/glad.h>

//------------------------------------------------------------------//

Game::Game()
    : mp_window(Window::get())
{
}

//------------------------------------------------------------------//

Game::~Game()
{
    if (mp_scene)
    {
        delete mp_scene;
        mp_scene = nullptr;
    }

    glUseProgram(0);
}

//------------------------------------------------------------------//

int Game::run()
{
    if (!mp_window)
    {
        Log(Info) << "Failed to start game.";
        return -1;
    }

    while (!glfwWindowShouldClose(mp_window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentTime = static_cast<float>(glfwGetTime());
        IdleManager::get().update(currentTime);
        PhysicsManager::get().update(currentTime);
        RenderingManager::get().update(currentTime);

        glfwSwapBuffers(mp_window);
        glfwPollEvents();
    }

    return 0;
}

//------------------------------------------------------------------//

void Game::setScene(Scene *s)
{
    if (mp_scene)
    {
        delete mp_scene;
    }

    mp_scene = s;
}

//------------------------------------------------------------------//
