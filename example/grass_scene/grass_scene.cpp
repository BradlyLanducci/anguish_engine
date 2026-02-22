#include <grass_scene/grass_scene.h>

#include <utilities/camera.h>

//------------------------------------------------------------------//

GrassScene::GrassScene()
    : mp_camera(new CameraObject())
    , mp_character(new Character())
    , mp_grass(new Grass())

{
    addChild(mp_camera);
    addChild(mp_character);
    addChild(mp_grass);

    mp_camera->follow(mp_character);

    Camera::get().setCurrent(mp_camera);
}

//------------------------------------------------------------------//
