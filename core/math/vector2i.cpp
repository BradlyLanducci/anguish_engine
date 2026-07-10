#include <math/vector2i.h>
#include <math/vector2.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

Vector2i::Vector2i(int _x, int _y)
    : x(_x)
    , y(_y)
{
}

//------------------------------------------------------------------//

Vector2i Vector2i::operator*(int i)
{
    this->x *= i;
    this->y *= i;
    return *this;
}

//------------------------------------------------------------------//

Vector2 Vector2i::operator*(double d) const
{
    Vector2 result;
    result.x = static_cast<double>(this->x) * d;
    result.y = static_cast<double>(this->y) * d;
    return result;
}

//------------------------------------------------------------------//

Vector2 Vector2i::operator*(const Vector2 &other) const
{
    Vector2 result;
    result.x = static_cast<double>(this->x) * other.x;
    result.y = static_cast<double>(this->y) * other.y;
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

Json::Value Vector2i::toJson() const
{
    Json::Value vector;

    vector["x"] = x;
    vector["y"] = y;

    return vector;
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
