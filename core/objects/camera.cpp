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

void Camera::setZoom(Vector2 zoom)
{
    m_view = glm::scale(glm::dmat4(1.0), { zoom.x, zoom.y, 1.f });
    viewChanged.emit(m_view);
}

//------------------------------------------------------------------//
