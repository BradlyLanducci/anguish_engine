#include <grass_scene/grass_scene.h>

#include <utilities/camera_manager.h>

//------------------------------------------------------------------//

GrassScene::GrassScene()
    : mp_camera(new Camera())
    , mp_character(new Character())
    , mp_grass(new Grass())

{
    addChild(mp_camera);
    addChild(mp_character);
    addChild(mp_grass);

    mp_camera->follow(mp_character);

    CameraManager::get().setCurrent(mp_camera);
}

//------------------------------------------------------------------//
