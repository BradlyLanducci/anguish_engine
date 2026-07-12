#pragma once

#include <objects/object.h>
#include <utilities/signal.h>

#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class Camera : public Object
{
public:
    Camera();

    /// @brief Returns the view matrix of this camera object.
    /// @return
    const glm::dmat4 &view() const;

    Vector2 zoom() const;

    /// @brief Follows the provided object whenever it moves.
    /// @param p_object The object to follow.
    /// @param followSpeed The speed in which the camera follows the object, 1.0 is locked.
    void follow(Object *p_object, double followSpeed = 1.0);

    /// @brief Sets the current zoom of the camera.
    /// @param zoom A 2D vector representing the x/y zoom.
    void setZoom(const Vector2 &zoom);

    Signal<glm::mat4> viewChanged;

private:
    void idleUpdate(double deltatTime);
    Vector2 getNextPosition(const Vector2 &targetPosition);

    Vector2 m_currentPosition;
    Vector2 m_targetPosition;

    double m_followSpeed{ 1.0 };

    Object *mp_objectToFollow{ nullptr };

    glm::dmat4 m_view{ 1.0 };
    Vector2 m_zoom;
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
