#pragma once

//------------------------------------------------------------------//

#include <math/rect.h>

//------------------------------------------------------------------//

class AABB
{
public:
    /// @brief Performs aabb collision detection on two rectangles.
    /// @param r1
    /// @param r2
    /// @return
    static bool aabb(const Rect &r1, const Rect &r2);

    /// @brief Provides the vector offset required to negate the collision
    /// in both axis.
    /// @param r1
    /// @param r2
    /// @return
    static Vector2 collide(const Rect &r1, const Rect &r2);

private:
    AABB() = default;
    ~AABB() = default;
};

//------------------------------------------------------------------//
