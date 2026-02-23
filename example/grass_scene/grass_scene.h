#pragma once

#include <grass_scene/environment/grass.h>
#include <grass_scene/player/character.h>

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
    Character *mp_character{ nullptr };
    Grass *mp_grass{ nullptr };
};

//------------------------------------------------------------------//
