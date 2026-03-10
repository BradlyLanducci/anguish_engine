#include <game.h>

#include <grass_scene/grass_scene.h>

//------------------------------------------------------------------//

int main(int argc, char *argv[])
{
    Game g;
    g.setRoot(new GrassScene);
    return g.run();
}

//------------------------------------------------------------------//
