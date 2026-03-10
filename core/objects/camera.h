#pragma once

//------------------------------------------------------------------//

#include <objects/object.h>

#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class Camera : public Object
{
public:
    Camera();

    const glm::dmat4 &view() const;

    void follow(Object *p_object);

private:
    Slot<Vector2> m_followObject;

    uint32_t m_objectMovedHandle;

    Object *mp_objectToFollow{ nullptr };

    glm::dmat4 m_view{ 1.0 };
};

//------------------------------------------------------------------//
