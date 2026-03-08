#pragma once

#include <iostream>

//------------------------------------------------------------------//

struct Vector2i;

//------------------------------------------------------------------//

struct Vector2
{
    Vector2(double _x, double _y);
    explicit Vector2(Vector2i vi);
    Vector2() = default;

    Vector2 operator*(double d) const;
    Vector2 operator*(const Vector2 &other) const;
    Vector2 operator*(const Vector2i &other) const;
    Vector2 &operator*=(const Vector2 &other);
    Vector2 operator+(const Vector2 &other) const;
    Vector2 &operator+=(const Vector2 &other);
    Vector2 operator-(const Vector2 &other) const;
    Vector2 operator/(const Vector2 &other) const;
    Vector2 operator/(double d) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &vector);

    void roundToInt();

    /// @brief Normalized direction vector
    Vector2 directionTo(const Vector2 &other);

    double distanceTo(const Vector2 &other);

    double x{ 0.0 };
    double y{ 0.0 };
};

//------------------------------------------------------------------//