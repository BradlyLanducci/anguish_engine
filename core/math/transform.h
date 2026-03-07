#pragma once

#include <math/vector2.h>

//------------------------------------------------------------------//

class Transform
{
public:
    Vector2 position;
    double rotation{};
    Vector2 scale{ 1.0, 1.0 };
};

//------------------------------------------------------------------//
