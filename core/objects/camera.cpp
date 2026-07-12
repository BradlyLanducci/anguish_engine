#include <objects/camera.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

Camera::Camera()
{
    addIdleCb([this](double deltaTime) { idleUpdate(deltaTime); });
}

//------------------------------------------------------------------//

const glm::dmat4 &Camera::view() const
{
    return m_view;
}

//------------------------------------------------------------------//

Vector2 Camera::zoom() const
{
    return m_zoom;
}

//------------------------------------------------------------------//

void Camera::follow(Object *p_object, double followSpeed)
{
    mp_objectToFollow = p_object;
    m_followSpeed = followSpeed;
}

//------------------------------------------------------------------//

void Camera::setZoom(const Vector2 &zoom)
{
    m_zoom = zoom;
    m_view = glm::scale(glm::dmat4(1.0), { zoom.x, zoom.y, 1.f });
    viewChanged.emit(m_view);
}

//------------------------------------------------------------------//

void Camera::idleUpdate(double deltatTime)
{
    if (mp_objectToFollow)
    {
        setGlobalPosition(getNextPosition(mp_objectToFollow->globalPosition()));
    }
}

//------------------------------------------------------------------//

Vector2 Camera::getNextPosition(const Vector2 &targetPosition)
{
    m_targetPosition = targetPosition;

    m_currentPosition.x = std::lerp(m_currentPosition.x, m_targetPosition.x, m_followSpeed);
    m_currentPosition.y = std::lerp(m_currentPosition.y, m_targetPosition.y, m_followSpeed);

    return m_currentPosition;
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
