#include <physics/aabb.h>
#include <math.h>

//------------------------------------------------------------------//

bool AABB::aabb(Rect r1, Rect r2)
{
    Vector2 tlR1 = r1.topLeft();
    Vector2 brR1 = r1.bottomRight();
    Vector2 tlR2 = r2.topLeft();
    Vector2 brR2 = r2.bottomRight();
    return (tlR1.x < brR2.x) && (brR1.x > tlR2.x) && (tlR1.y < brR2.y) && (brR1.y > tlR2.y);
}

//------------------------------------------------------------------//

Vector2 AABB::collide(Rect r1, Rect r2)
{
    Vector2 tlR1 = r1.topLeft();
    Vector2 brR1 = r1.bottomRight();
    Vector2 tlR2 = r2.topLeft();
    Vector2 brR2 = r2.bottomRight();

    bool horizontal = (tlR1.x < brR2.x) && (brR1.x > tlR2.x);
    bool vertical = (tlR1.y < brR2.y) && (brR1.y > tlR2.y);

    float horizontalOffset = 0.f; // horizontal ? tlR2.x - brR1.x : 0.f;
    float verticalOffset = vertical ? tlR2.y - brR1.y : 0.f;

    return Vector2(std::ceil(horizontalOffset), std::ceil(verticalOffset));
}

//------------------------------------------------------------------//
