#include <app.h>

#include <layers/game_layer.h>
#include <grass_scene/grass_scene.h>

//------------------------------------------------------------------//

int main(int argc, char *argv[])
{
    App app;
    app.addLayer<GameLayer>(new GrassScene());
    return app.run();
}

//------------------------------------------------------------------//
