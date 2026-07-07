#include <app.h>

#include <main_scene/main_scene.h>
#include <layers/game_layer.h>

//------------------------------------------------------------------//

int main(int argc, char *argv[])
{
    AE::App app;
    app.addLayer<AE::GameLayer>(new MainScene());
    return app.run();
}

//------------------------------------------------------------------//
