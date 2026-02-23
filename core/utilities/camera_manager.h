#pragma once

#include <objects/camera.h>

//------------------------------------------------------------------//

class CameraManager
{
public:
    static CameraManager &get();

    void setCurrent(Camera *p_camera);

private:
    CameraManager() = default;
    ~CameraManager() = default;

    Camera *mp_camera{ nullptr };
};

//------------------------------------------------------------------//
