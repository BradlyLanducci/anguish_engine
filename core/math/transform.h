#pragma once

#include <math/vector2.h>

//------------------------------------------------------------------//

class Transform
{
public:
    Vector2 position;
    float rotation{};
    Vector2 scale{ 1.f, 1.f };
};

//------------------------------------------------------------------//
