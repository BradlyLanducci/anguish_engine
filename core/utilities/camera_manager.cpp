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

void CameraManager::setCurrent(Camera *p_camera)
{
    if (mp_camera)
    {
        // We can remove all connections in this case
        mp_camera->moved.removeConnections();
    }

    mp_camera = p_camera;

    (void)mp_camera->moved.connect(
        [this]()
        {
            Vector2 gp{ mp_camera->globalPosition() };
            Vector2 windowSize{ Window::size() };
            glm::mat4 translate{ glm::translate(mp_camera->view(),
                                                { -gp.x + static_cast<float>(windowSize.x) / 2.f,
                                                  -gp.y + static_cast<float>(windowSize.y) / 2.f, 0.0f }) };
            RenderingManager::get().setViewMatrix(translate);
        });
}

//------------------------------------------------------------------//
