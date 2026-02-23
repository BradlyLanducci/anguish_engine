#pragma once

#include <cstdint>

//------------------------------------------------------------------//

struct Vector2;

//------------------------------------------------------------------//

struct Vector2i
{
    Vector2i(uint32_t _x, uint32_t _y);
    Vector2i() = default;

    Vector2i operator*(uint32_t i);
    Vector2 operator*(float f) const;
    Vector2 operator*(const Vector2 &other) const;
    Vector2i operator*(const Vector2i &other);

    uint32_t x{ 0 };
    uint32_t y{ 0 };
};

//------------------------------------------------------------------//