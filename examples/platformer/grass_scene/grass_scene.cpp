#include <grass_scene/grass_scene.h>

#include <utilities/camera_manager.h>
#include <utilities/file_io.h>

//------------------------------------------------------------------//

GrassScene::GrassScene()
    : mp_camera(new AE::Camera())
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

    mp_grass1->setGlobalPosition(AE::Vector2(0, 600));
    mp_grass2->setGlobalPosition(AE::Vector2(400, 575));
    mp_cabbage->setGlobalPosition(AE::Vector2(300, 0));

    mp_camera->follow(mp_player);

    AE::CameraManager::get().setCurrent(mp_camera);
    mp_player->deserialize(AE::FileIO::readJson("build/save_file.json"));
}

//------------------------------------------------------------------//

GrassScene::~GrassScene()
{
    Json::Value data{ mp_player->serialize() };
    (void)AE::FileIO::writeJson("build/save_file.json", data);
}

//------------------------------------------------------------------//
