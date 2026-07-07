#include <utilities/camera_manager.h>
#include <renderer/rendering_manager.h>
#include <utilities/window.h>

//------------------------------------------------------------------//

CameraManager &CameraManager::get()
{
    static CameraManager c;
    return c;
}

//------------------------------------------------------------------//

CameraManager::CameraManager()
    : m_cameraMoved(
          [this](Vector2 newPosition)
          {
              Vector2 gp{ mp_camera->globalPosition() };
              Vector2 windowSize{ Window::size() };
              glm::dmat4 translate{ glm::translate(mp_camera->view(),
                                                   { -gp.x + static_cast<double>(windowSize.x) / 2.f,
                                                     -gp.y + static_cast<double>(windowSize.y) / 2.f, 0.0f }) };
              RenderingManager::get().setViewMatrix(translate);
          })
    , m_cameraViewChanged([this](glm::mat4 view) { RenderingManager::get().setViewMatrix(view); })
{
}

//------------------------------------------------------------------//

void CameraManager::setCurrent(Camera *p_camera)
{
    if (mp_camera)
    {
        mp_camera->moved.disconnectAll();
        mp_camera->viewChanged.disconnectAll();
    }

    mp_camera = p_camera;

    mp_camera->moved.connect(m_cameraMoved);
    mp_camera->viewChanged.connect(m_cameraViewChanged);
}

//------------------------------------------------------------------//
