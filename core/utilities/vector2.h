#pragma once

#include <iostream>

//------------------------------------------------------------------//

struct Vector2i;

//------------------------------------------------------------------//

struct Vector2
{
    Vector2(float _x, float _y);
    explicit Vector2(Vector2i vi);
    Vector2() = default;

    Vector2 operator*(float f) const;
    Vector2 operator*(const Vector2 &other) const;
    Vector2 operator*(const Vector2i &other) const;
    Vector2 &operator*=(const Vector2 &other);
    Vector2 operator+(const Vector2 &other) const;
    Vector2 &operator+=(const Vector2 &other);
    Vector2 operator-(const Vector2 &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &vector);

    void roundToInt();

    float x{ 0.f };
    float y{ 0.f };
};

//------------------------------------------------------------------//