#include <utilities/vector2i.h>
#include <utilities/vector2.h>

//------------------------------------------------------------------//

Vector2::Vector2(float _x, float _y)
    : x(_x)
    , y(_y)
{
}

//------------------------------------------------------------------//

Vector2::Vector2(Vector2i vi)
    : x(static_cast<float>(vi.x))
    , y(static_cast<float>(vi.y))
{
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(float f) const
{
    Vector2 result;
    result.x = this->x * f;
    result.y = this->y * f;
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
    x = (float)(static_cast<int32_t>(x));
    y = (float)(static_cast<int32_t>(y));
}

//------------------------------------------------------------------//
