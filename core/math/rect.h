#pragma once

//------------------------------------------------------------------//

#include <math/vector2.h>

//------------------------------------------------------------------//

struct Rect
{
    Rect(Vector2 _origin, Vector2 _size);
    Rect() = default;

    Vector2 origin;
    Vector2 size;

    [[nodiscard]] Vector2 topLeft() const;
    [[nodiscard]] Vector2 topRight() const;
    [[nodiscard]] Vector2 bottomLeft() const;
    [[nodiscard]] Vector2 bottomRight() const;
};

//------------------------------------------------------------------//
