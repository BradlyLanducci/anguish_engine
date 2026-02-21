#pragma once

#include <grass_scene/environment/grass.h>
#include <grass_scene/player/character.h>
#include <scenes/scene.h>

//------------------------------------------------------------------//

class GrassScene : public Scene
{
public:
    GrassScene();
    ~GrassScene() override = default;

private:
    Character *c{ nullptr };
    Grass *g{ nullptr };
};

//------------------------------------------------------------------//
