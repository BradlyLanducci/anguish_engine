#include <utilities/rect.h>

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
