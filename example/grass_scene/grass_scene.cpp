#include <grass_scene/grass_scene.h>

#include <utilities/camera_manager.h>

//------------------------------------------------------------------//

GrassScene::GrassScene()
    : mp_camera(new Camera())
    , mp_character(new Character())
    , mp_grass1(new Grass())
    , mp_grass2(new Grass())

{
    addChild(mp_camera);
    addChild(mp_character);
    addChild(mp_grass1);
    addChild(mp_grass2);

    mp_grass1->setGlobalPosition(Vector2(0, 600));
    mp_grass2->setGlobalPosition(Vector2(400, 0));

    mp_camera->follow(mp_character);

    CameraManager::get().setCurrent(mp_camera);
}

//------------------------------------------------------------------//
