#pragma once

#include <grass_scene/environment/grass.h>
#include <grass_scene/player/player.h>

#include <objects/camera.h>
#include <scenes/scene.h>

//------------------------------------------------------------------//

class GrassScene : public Scene
{
public:
    GrassScene();
    ~GrassScene() override = default;

private:
    Camera *mp_camera;
    Player *mp_player{ nullptr };
    Grass *mp_grass1{ nullptr };
    Grass *mp_grass2{ nullptr };
};

//------------------------------------------------------------------//
