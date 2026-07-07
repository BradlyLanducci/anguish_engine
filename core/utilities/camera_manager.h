#pragma once

//------------------------------------------------------------------//

#include <objects/camera.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class CameraManager
{
public:
    static CameraManager &get();

    void setCurrent(Camera *p_camera);

private:
    CameraManager();
    ~CameraManager() = default;

    Slot<Vector2> m_cameraMoved;
    Slot<glm::mat4> m_cameraViewChanged;

    Camera *mp_camera{ nullptr };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
