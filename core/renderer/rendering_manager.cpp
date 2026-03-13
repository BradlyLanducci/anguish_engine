#include <renderer/rendering_manager.h>
#include <objects/sprite.h>
#include <utilities/window.h>
#include <utilities/time.h>
#include <utilities/logger.h>

#include <algorithm>

//------------------------------------------------------------------//

RenderingManager &RenderingManager::get()
{
    static RenderingManager p;
    return p;
}

//------------------------------------------------------------------//

void RenderingManager::destroy()
{
    m_queue.clear();
}

//------------------------------------------------------------------//

void RenderingManager::addObject(RenderedObject *p_object)
{
    m_queue.add(p_object);
}

//------------------------------------------------------------------//

void RenderingManager::removeObject(RenderedObject *p_object)
{
    m_queue.remove(p_object);
}

//------------------------------------------------------------------//

void RenderingManager::setViewMatrix(const glm::dmat4 &view)
{
    m_view = view;
}

//------------------------------------------------------------------//

void RenderingManager::render()
{
    Vector2 windowSize{ Window::size() };
    m_projection = glm::ortho(0.0, windowSize.x, windowSize.y, 0.0);

    m_queue.update();

    for (const auto &sprite : m_queue)
    {
        /// TODO: Batching.. this is very inefficient
        sprite->setProjectionMatrix(m_projection);
        sprite->setViewMatrix(m_view);
        sprite->draw();
    }
}

//------------------------------------------------------------------//