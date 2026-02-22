#pragma once

#include <utilities/data_structures.h>
#include <objects/camera_object.h>

//------------------------------------------------------------------//

class Camera
{
public:
    static Camera &get();

    void setCurrent(CameraObject *p_camera);

private:
    Camera() = default;
    ~Camera() = default;

    CameraObject *mp_camera{ nullptr };
};

//------------------------------------------------------------------//
