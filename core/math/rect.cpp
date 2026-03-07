#include <math/rect.h>

//------------------------------------------------------------------//
Rect::Rect(Vector2 _origin, Vector2 _size)
    : origin(_origin)
    , size(_size)
{
}

//------------------------------------------------------------------//

Vector2 Rect::topLeft() const
{
    return { origin };
}

//------------------------------------------------------------------//

Vector2 Rect::topRight() const
{
    return { origin.x + size.x, origin.y };
}

//------------------------------------------------------------------//

Vector2 Rect::bottomLeft() const
{
    return { origin.x, origin.y + size.y };
}

//------------------------------------------------------------------//

Vector2 Rect::bottomRight() const
{
    return { origin + size };
}

//------------------------------------------------------------------//

std::ostream &operator<<(std::ostream &os, const Vector2 &vector)
{
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}
