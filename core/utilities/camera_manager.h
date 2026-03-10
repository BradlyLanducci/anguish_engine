#pragma once

//------------------------------------------------------------------//

#include <objects/camera.h>

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

    Camera *mp_camera{ nullptr };
};

//------------------------------------------------------------------//
