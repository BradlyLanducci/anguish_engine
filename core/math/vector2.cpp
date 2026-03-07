#include <math/vector2i.h>
#include <math/vector2.h>

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

//------------------------------------------------------------------//

void Vector2::roundToInt()
{
    x = (double)(static_cast<int32_t>(x));
    y = (double)(static_cast<int32_t>(y));
}

//------------------------------------------------------------------//
