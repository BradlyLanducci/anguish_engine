#include <game.h>

#include <grass_scene/grass_scene.h>

//------------------------------------------------------------------//

int main(int argc, char *argv[])
{
    Game g;
    g.setScene(new GrassScene);
    return g.run();
}

//------------------------------------------------------------------//
