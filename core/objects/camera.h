#pragma once

//------------------------------------------------------------------//

#include <objects/object.h>

#include <glm/gtc/matrix_transform.hpp>

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

private:
    Slot<Vector2> m_followObject;

    uint32_t m_objectMovedHandle;

    Object *mp_objectToFollow{ nullptr };

    glm::dmat4 m_view{ 1.0 };
};

//------------------------------------------------------------------//
