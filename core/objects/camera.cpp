#include <objects/camera.h>

//------------------------------------------------------------------//

Camera::Camera()
    : m_followObject([this](Vector2 newPosition) { setGlobalPosition(newPosition); })
{
}

//------------------------------------------------------------------//

const glm::dmat4 &Camera::view() const
{
    return m_view;
}

//------------------------------------------------------------------//

void Camera::follow(Object *p_object)
{
    if (mp_objectToFollow)
    {
        mp_objectToFollow->moved.disconnect(m_followObject);
    }
    mp_objectToFollow = p_object;
    p_object->moved.connect(m_followObject);
}

//------------------------------------------------------------------//
