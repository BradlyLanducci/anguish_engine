#pragma once

#include <utilities/vector2.h>
#include <utilities/matrix.h>

//------------------------------------------------------------------//

class Transform
{
public:
    Vector2 position;
    Vector2 rotation;
    Vector2 scale{ 1.f, 1.f };
};

//------------------------------------------------------------------//
