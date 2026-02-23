#pragma once

#include <utilities/data_structures.h>
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
