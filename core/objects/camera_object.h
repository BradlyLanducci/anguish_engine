#pragma once

#include <objects/object.h>

#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class CameraObject : public Object
{
public:
    CameraObject();

    glm::mat4 view() const;

    void follow(Object *p_object);

private:
    void followObject();

    uint32_t m_objectMovedHandle;

    Object *mp_objectToFollow{ nullptr };

    glm::mat4 m_view{ 1.f };
};

//------------------------------------------------------------------//
