#pragma once

//------------------------------------------------------------------//

#include <cstdint>
#include <iostream>

//------------------------------------------------------------------//

struct Vector2i;

struct Vector2
{
    Vector2(float _x, float _y);
    explicit Vector2(Vector2i vi);
    Vector2() = default;

    Vector2 operator*(float f) const;
    Vector2 operator*(const Vector2 &other) const;
    Vector2 operator*(const Vector2i &other) const;
    Vector2 operator+(const Vector2 &other) const;
    Vector2 operator-(const Vector2 &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &vector);

    void roundToInt();

    float x{ 0.f };
    float y{ 0.f };
};

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
    [[nodiscard]] Vector2 bottomRight();
};

//------------------------------------------------------------------//
