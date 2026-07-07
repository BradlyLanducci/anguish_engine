#pragma once

//------------------------------------------------------------------//

#include <ae_core.h>

#include <cstdint>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

struct Vector2;

//------------------------------------------------------------------//

struct Vector2i
{
    Vector2i(int _x, int _y);
    Vector2i() = default;

    Vector2i operator*(int i);
    Vector2 operator*(double d) const;
    Vector2 operator*(const Vector2 &other) const;
    Vector2i operator*(const Vector2i &other);

    int x{ 0 };
    int y{ 0 };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
