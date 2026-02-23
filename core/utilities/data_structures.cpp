#include <utilities/data_structures.h>

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

Rect::Rect(Vector2 _origin, Vector2 _size, Vector2 _scale)
    : origin(_origin)
    , size(_size)
    , scale(_scale)
{
}

//------------------------------------------------------------------//

Vector2 Rect::topLeft() const
{
    return { this->origin };
}

//------------------------------------------------------------------//

Vector2 Rect::topRight() const
{
    return { this->origin.x + this->size.x * this->scale.x, this->origin.y };
}

//------------------------------------------------------------------//

Vector2 Rect::bottomLeft() const
{
    return { this->origin.x, this->origin.y + this->size.y * this->scale.y };
}

//------------------------------------------------------------------//

Vector2 Rect::bottomRight() const
{
    return { this->origin + this->size * this->scale };
}

//------------------------------------------------------------------//

std::ostream &operator<<(std::ostream &os, const Vector2 &vector)
{
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}
