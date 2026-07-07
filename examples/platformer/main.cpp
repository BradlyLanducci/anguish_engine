#include <app.h>

#include <layers/game_layer.h>
#include <grass_scene/grass_scene.h>

//------------------------------------------------------------------//

int main(int argc, char *argv[])
{
    AE::App app;
    app.addLayer<AE::GameLayer>(new GrassScene());
    return app.run();
}

//------------------------------------------------------------------//
