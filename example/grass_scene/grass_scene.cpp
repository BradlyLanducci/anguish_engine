#include <grass_scene/grass_scene.h>

#include <utilities/camera_manager.h>

//------------------------------------------------------------------//

GrassScene::GrassScene()
    : mp_camera(new Camera())
    , mp_player(new Player())
    , mp_cabbage(new CabbageBoy())
    , mp_grass1(new Grass())
    , mp_grass2(new Grass())

{
    addChild(mp_camera);
    addChild(mp_player);
    addChild(mp_cabbage);
    addChild(mp_grass1);
    addChild(mp_grass2);

    mp_grass1->setGlobalPosition(Vector2(0, 600));
    mp_grass2->setGlobalPosition(Vector2(400, 575));
    mp_cabbage->setGlobalPosition(Vector2(300, 0));

    mp_camera->follow(mp_player);

    CameraManager::get().setCurrent(mp_camera);
}

//------------------------------------------------------------------//
