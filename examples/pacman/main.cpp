#include <app.h>

#include <main_scene/main_scene.h>
#include <layers/game_layer.h>

//------------------------------------------------------------------//

int main(int argc, char *argv[])
{
    App app;
    app.addLayer<GameLayer>(new MainScene());
    return app.run();
}

//------------------------------------------------------------------//
