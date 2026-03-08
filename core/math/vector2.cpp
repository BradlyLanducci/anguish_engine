#include <math/vector2i.h>
#include <math/vector2.h>

#include <cassert>

//------------------------------------------------------------------//

Vector2::Vector2(double _x, double _y)
    : x(_x)
    , y(_y)
{
}

//------------------------------------------------------------------//

Vector2::Vector2(Vector2i vi)
    : x(static_cast<double>(vi.x))
    , y(static_cast<double>(vi.y))
{
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(double d) const
{
    Vector2 result;
    result.x = x * d;
    result.y = y * d;
    return result;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(const Vector2 &other) const
{
    Vector2 result;
    result.x = this->x * other.x;
    result.y = this->y * other.y;
    return result;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(const Vector2i &other) const
{
    Vector2 result;
    result.x = this->x * other.x;
    result.y = this->y * other.y;
    return result;
}

//------------------------------------------------------------------//

Vector2 &Vector2::operator*=(const Vector2 &other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator+(const Vector2 &other) const
{
    Vector2 result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
}

//------------------------------------------------------------------//

Vector2 &Vector2::operator+=(const Vector2 &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator-(const Vector2 &other) const
{
    Vector2 result;
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    return result;
}

Vector2 Vector2::operator/(const Vector2 &other) const
{
    assert(other.x > 0.0);
    assert(other.y > 0.0);

    Vector2 result;
    result.x = this->x / other.x;
    result.y = this->y / other.y;
    return result;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator/(double d) const
{
    assert(d > 0.0);

    Vector2 result;
    result.x = this->x / d;
    result.y = this->y / d;
    return result;
}

//------------------------------------------------------------------//

void Vector2::roundToInt()
{
    x = (double)(static_cast<int32_t>(x));
    y = (double)(static_cast<int32_t>(y));
}

//------------------------------------------------------------------//

Vector2 Vector2::directionTo(const Vector2 &other)
{
    return { Vector2(other.x - x, other.y - y) / distanceTo(other) };
}

//------------------------------------------------------------------//

double Vector2::distanceTo(const Vector2 &other)
{
    return std::sqrt(std::pow(other.x - x, 2.0) + std::pow(other.y - y, 2.0));
}

//------------------------------------------------------------------//
