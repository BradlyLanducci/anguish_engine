#include <main_scene/main_scene.h>

#include <objects/camera.h>
#include <objects/collision.h>
#include <objects/sprite.h>
#include <utilities/camera_manager.h>
#include <renderer/rendering_manager.h>
#include <utilities/window.h>

//------------------------------------------------------------------//

MainScene::MainScene()
    : mp_camera(new Camera())
    , mp_player(new BananaMan(m_board))
{
    constexpr int BaseWidth{ 224 };
    constexpr int BaseHeight{ 288 };

    constexpr int Scalar{ 3 };
    constexpr int ScaledWidth{ Scalar * BaseWidth };
    constexpr int ScaledHeight{ Scalar * BaseHeight };

    addChild(mp_camera);
    CameraManager::get().setCurrent(mp_camera);
    Window::setWindowSize(Vector2i{ ScaledWidth, ScaledHeight });
    mp_camera->setZoom({ 3.f, 3.f });

    addChild(mp_player);

    constexpr double SquareSide{ 16 };
    for (size_t r = 0; r < m_board.size(); r++)
    {
        for (size_t c = 0; c < m_board[0].size(); c++)
        {
            if (m_board[r][c])
            {
                Sprite *p_sprite{ new Sprite() };

                Collision *p_collision{ new Collision() };
                p_collision->setSize({ SquareSide, SquareSide });

                p_sprite->addChild(p_collision);
                p_sprite->setTexture("examples/platformer/grass_scene/textures/grass.png");
                p_sprite->setSize({ SquareSide, SquareSide });
                p_sprite->setGlobalPosition(
                    { SquareSide * static_cast<double>(c), SquareSide * static_cast<double>(r) });

                addChild(p_sprite);
            }
        }
    }

    CameraManager::get().setCurrent(mp_camera);
}

//------------------------------------------------------------------//
