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
              glm::mat4 translate{ glm::translate(mp_camera->view(),
                                                  { -gp.x + static_cast<float>(windowSize.x) / 2.f,
                                                    -gp.y + static_cast<float>(windowSize.y) / 2.f, 0.0f }) };
              RenderingManager::get().setViewMatrix(translate);
          })
{
}

void CameraManager::setCurrent(Camera *p_camera)
{
    if (mp_camera)
    {
        mp_camera->moved.disconnectAll();
    }

    mp_camera = p_camera;

    mp_camera->moved.connect(m_cameraMoved);
}

//------------------------------------------------------------------//
