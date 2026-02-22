#include <objects/camera_object.h>

//------------------------------------------------------------------//

CameraObject::CameraObject()
    : Object(true, false)
{
}

//------------------------------------------------------------------//

glm::mat4 CameraObject::view() const
{
    return m_view;
}

//------------------------------------------------------------------//

void CameraObject::follow(Object *p_object)
{
    if (mp_objectToFollow)
    {
        mp_objectToFollow->moved.disconnect(m_objectMovedHandle);
    }
    mp_objectToFollow = p_object;
    m_objectMovedHandle = p_object->moved.connect([this]() { followObject(); });
}

//------------------------------------------------------------------//

void CameraObject::followObject()
{
    setGlobalPosition(mp_objectToFollow->globalPosition());
}

//------------------------------------------------------------------//
