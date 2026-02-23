#include <utilities/vector2i.h>
#include <utilities/vector2.h>

//------------------------------------------------------------------//

Vector2i::Vector2i(uint32_t _x, uint32_t _y)
    : x(_x)
    , y(_y)
{
}

//------------------------------------------------------------------//

Vector2i Vector2i::operator*(uint32_t i)
{
    this->x *= i;
    this->y *= i;
    return *this;
}

//------------------------------------------------------------------//

Vector2 Vector2i::operator*(float f) const
{
    Vector2 result;
    result.x = static_cast<float>(this->x) * f;
    result.y = static_cast<float>(this->y) * f;
    return result;
}

//------------------------------------------------------------------//

Vector2 Vector2i::operator*(const Vector2 &other) const
{
    Vector2 result;
    result.x = static_cast<float>(this->x) * other.x;
    result.y = static_cast<float>(this->y) * other.y;
    return result;
}

//------------------------------------------------------------------//

Vector2i Vector2i::operator*(const Vector2i &other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

//------------------------------------------------------------------//
