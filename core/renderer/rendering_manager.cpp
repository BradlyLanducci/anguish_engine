#include <renderer/rendering_manager.h>
#include <objects/sprite.h>
#include <utilities/window.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

std::vector<Sprite *> RenderingManager::m_sprites;
glm::dmat4 RenderingManager::m_projection{ 1.f };
glm::dmat4 RenderingManager::m_view{ 1.f };

//------------------------------------------------------------------//

RenderingManager &RenderingManager::get()
{
    static RenderingManager p;
    return p;
}

//------------------------------------------------------------------//

RenderingManager::~RenderingManager()
{
    for (const auto &p_sprite : m_sprites)
    {
        Log(Error) << "Leaked sprite " << p_sprite;
    }
}

//------------------------------------------------------------------//

void RenderingManager::addSprite(Sprite *p_sprite)
{
    m_sprites.push_back(p_sprite);
}

//------------------------------------------------------------------//

void RenderingManager::removeSprite(Sprite *p_sprite)
{
    std::erase(m_sprites, p_sprite);
}

//------------------------------------------------------------------//

void RenderingManager::update(double currentTime)
{
    for (const auto &sprite : m_sprites)
    {
        Vector2 windowSize{ Window::size() };
        m_projection = glm::ortho(0.0, windowSize.x, windowSize.y, 0.0);
        sprite->setProjectionMatrix(m_projection);
        /// TODO: Batching.. this is very inefficient
        sprite->setViewMatrix(m_view);
        sprite->draw();
    }
}

//------------------------------------------------------------------//

void RenderingManager::setViewMatrix(const glm::dmat4 &view)
{
    m_view = view;
}

//------------------------------------------------------------------//
