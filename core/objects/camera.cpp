#include <objects/camera.h>

//------------------------------------------------------------------//

Camera::Camera()
    : Object(true, false)
{
}

//------------------------------------------------------------------//

glm::mat4 Camera::view() const
{
    return m_view;
}

//------------------------------------------------------------------//

void Camera::follow(Object *p_object)
{
    if (mp_objectToFollow)
    {
        mp_objectToFollow->moved.disconnect(m_objectMovedHandle);
    }
    mp_objectToFollow = p_object;
    m_objectMovedHandle = p_object->moved.connect([this]() { followObject(); });
}

//------------------------------------------------------------------//

void Camera::followObject()
{
    setGlobalPosition(mp_objectToFollow->globalPosition());
}

//------------------------------------------------------------------//
