#include <grass_scene/enemies/cabbage_boy.h>

//------------------------------------------------------------------//

CabbageBoy::CabbageBoy()
    : Character(new Collision())
    , mp_sprite(new AnimatedSprite())
{
    addPhysicsCb([this](double deltaTimeTime) { physicsUpdate(deltaTimeTime); });

    setScale({ 0.125, 0.125 });

    addChild(mp_sprite);
    addChild(collision());

    Shared<Spritesheet> idle{ std::make_shared<Spritesheet>("example/grass_scene/textures/idle.png", 1, 1, 1, 1,
                                                            true) };
    mp_sprite->addAnimation("idle", idle);

    collision()->setSize(Vector2(150, 175));

    mp_sprite->playAnimation("idle");
}

//------------------------------------------------------------------//

void CabbageBoy::physicsUpdate(double deltaTime)
{
    Vector2 gp{ globalPosition() };
    double gravity{ 300.0 * (double)deltaTime };
    gp.y += gravity;
    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
