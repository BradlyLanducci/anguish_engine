#pragma once

//------------------------------------------------------------------//

#include <utilities/vector2.h>

//------------------------------------------------------------------//

struct Rect
{
    Rect(Vector2 _origin, Vector2 _size, Vector2 _scale);
    Rect() = default;

    Vector2 origin;
    Vector2 size;
    Vector2 scale{ 1.f, 1.f };

    [[nodiscard]] Vector2 topLeft() const;
    [[nodiscard]] Vector2 topRight() const;
    [[nodiscard]] Vector2 bottomLeft() const;
    [[nodiscard]] Vector2 bottomRight() const;
};

//------------------------------------------------------------------//
