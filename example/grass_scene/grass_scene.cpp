#include <grass_scene/grass_scene.h>

//------------------------------------------------------------------//

GrassScene::GrassScene()
    : c(new Character())
    , g(new Grass())
{
    addChild(c);
    addChild(g);
}

//------------------------------------------------------------------//
