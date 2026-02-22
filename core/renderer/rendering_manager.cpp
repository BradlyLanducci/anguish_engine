#include <renderer/rendering_manager.h>
#include <objects/sprite_object.h>
#include <utilities/window.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

constexpr float PHYSICS_INTERVAL = 1.f / 60.f;

//------------------------------------------------------------------//

std::vector<Sprite *> RenderingManager::m_sprites;
glm::mat4 RenderingManager::m_projection{ 1.f };
glm::mat4 RenderingManager::m_view{ 1.f };

//------------------------------------------------------------------//

RenderingManager &RenderingManager::get()
{
    static RenderingManager p;
    return p;
}

//------------------------------------------------------------------//

void RenderingManager::addObject(Sprite *sprite)
{
    m_sprites.push_back(sprite);
    LOG(INFO) << "Added object now we have " << m_sprites.size() << " objects";
}

//------------------------------------------------------------------//

void RenderingManager::update(float currentTime)
{
    for (const auto &sprite : m_sprites)
    {
        Vector2 windowSize{ Window::size() };
        m_projection = glm::ortho(0.0f, windowSize.x, windowSize.y, 0.0f);
        sprite->setProjectionMatrix(m_projection);
        sprite->setViewMatrix(m_view);
        sprite->draw();
    }
}

//------------------------------------------------------------------//

void RenderingManager::setViewMatrix(const glm::mat4 &view)
{
    m_view = view;
}

//------------------------------------------------------------------//
