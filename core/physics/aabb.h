#pragma once

//------------------------------------------------------------------//

#include <utilities/data_structures.h>

//------------------------------------------------------------------//

class AABB
{
public:
    static bool aabb(const Rect &r1, const Rect &r2);
    static Vector2 collide(const Rect &r1, const Rect &r2);

private:
    AABB() = default;
    ~AABB() = default;
};

//------------------------------------------------------------------//
