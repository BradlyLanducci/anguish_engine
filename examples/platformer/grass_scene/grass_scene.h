#pragma once

#include <grass_scene/environment/grass.h>
#include <grass_scene/player/player.h>
#include <grass_scene/enemies/cabbage_boy.h>

#include <objects/camera.h>

//------------------------------------------------------------------//

class GrassScene : public AE::Object
{
public:
    GrassScene();
    ~GrassScene();

private:
    AE::Camera *mp_camera;
    Player *mp_player;
    CabbageBoy *mp_cabbage;
    Grass *mp_grass1;
    Grass *mp_grass2;
};

//------------------------------------------------------------------//
