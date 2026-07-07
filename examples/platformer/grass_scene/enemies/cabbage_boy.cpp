#include <grass_scene/enemies/cabbage_boy.h>

//------------------------------------------------------------------//

CabbageBoy::CabbageBoy()
    : AE::Character(new AE::Collision())
    , mp_sprite(new AE::AnimatedSprite())
{
    addPhysicsCb([this](double deltaTimeTime) { physicsUpdate(deltaTimeTime); });

    setScale({ 0.125, 0.125 });

    addChild(mp_sprite);
    addChild(collision());

    auto idle{ std::make_shared<AE::Spritesheet>("examples/platformer/grass_scene/textures/idle.png", 1, 1, 1, 1,
                                                 true) };
    mp_sprite->addAnimation("idle", idle);

    collision()->setSize(AE::Vector2(150, 175));

    mp_sprite->playAnimation("idle");
}

//------------------------------------------------------------------//

void CabbageBoy::physicsUpdate(double deltaTime)
{
    AE::Vector2 gp{ globalPosition() };
    double gravity{ 300.0 * (double)deltaTime };
    gp.y += gravity;
    setGlobalPosition(gp);
}

//------------------------------------------------------------------//
