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

    /// @brief Follows the provided object whenever it moves.
    /// @param p_object The object to follow.
    void follow(Object *p_object);

    /// @brief Sets the current zoom of the camera.
    /// @param zoom A 2D vector representing the x/y zoom.
    void setZoom(Vector2 zoom);

    Signal<glm::mat4> viewChanged;

private:
    Slot<Vector2> m_followObject;

    Object *mp_objectToFollow{ nullptr };

    glm::dmat4 m_view{ 1.0 };
    glm::dvec3 m_zoom{ 1.0 };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
