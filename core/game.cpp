#include <game.h>
#include <idle/idle_manager.h>
#include <memory/memory_manager.h>
#include <physics/physics_manager.h>
#include <renderer/rendering_manager.h>
#include <objects/object.h>
#include <utilities/time.h>
#include <utilities/logger.h>

#include <glad/gl.h>

//------------------------------------------------------------------//

Game::Game()
    : mp_window(Window::get())
{
}

//------------------------------------------------------------------//

Game::~Game()
{
    if (mp_root)
    {
        delete mp_root;
        mp_root = nullptr;
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

        double currentTime = static_cast<double>(Time::now_s());
        IdleManager::get().update(currentTime);
        PhysicsManager::get().update(currentTime);
        RenderingManager::get().update(currentTime);
        MemoryManager::get().process();

        glfwSwapBuffers(mp_window);
        glfwPollEvents();
    }

    return 0;
}

//------------------------------------------------------------------//

void Game::setRoot(Object *p_object)
{
    if (mp_root)
    {
        delete mp_root;
    }

    mp_root = p_object;
}

//------------------------------------------------------------------//
