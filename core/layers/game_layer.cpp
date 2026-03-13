#include <layers/game_layer.h>

#include <idle/idle_manager.h>
#include <audio/audio_manager.h>
#include <memory/memory_manager.h>
#include <physics/physics_manager.h>
#include <renderer/rendering_manager.h>
#include <objects/object.h>

//------------------------------------------------------------------//

GameLayer::GameLayer(Object *p_object)
{
    setRoot(p_object);
}

//------------------------------------------------------------------//

GameLayer::~GameLayer()
{
    if (mp_root)
    {
        delete mp_root;
        mp_root = nullptr;
    }
}

//------------------------------------------------------------------//

void GameLayer::destroy()
{
    RenderingManager::get().destroy();
    PhysicsManager::get().destroy();
    IdleManager::get().destroy();
    AudioManager::get().destroy();
    MemoryManager::get().destroy();
}

//------------------------------------------------------------------//

void GameLayer::setRoot(Object *p_object)
{
    if (mp_root)
    {
        delete mp_root;
    }

    mp_root = p_object;
}

//------------------------------------------------------------------//

void GameLayer::update(double deltaTime)
{
    MemoryManager::get().process();
    AudioManager::get().process();

    IdleManager::get().update(deltaTime);
    PhysicsManager::get().update(deltaTime);
}

//------------------------------------------------------------------//

void GameLayer::render()
{
    RenderingManager::get().render();
}

//------------------------------------------------------------------//