#include <renderer/rendering_manager.h>
#include <objects/sprite.h>
#include <utilities/window.h>
#include <utilities/time.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

RenderingManager &RenderingManager::get()
{
    static RenderingManager p;
    return p;
}

//------------------------------------------------------------------//

RenderingManager::~RenderingManager()
{
    for (const auto &p_sprite : m_objects)
    {
        Log(Error) << "Leaked sprite " << p_sprite;
    }
}

//------------------------------------------------------------------//

void RenderingManager::addObject(RenderedObject *p_object)
{
    m_objects.push_back(p_object);
}

//------------------------------------------------------------------//

void RenderingManager::removeObject(RenderedObject *p_object)
{
    std::erase(m_objects, p_object);
}

//------------------------------------------------------------------//

void RenderingManager::update(double currentTime)
{
    static double lastTime{ static_cast<double>(Time::now_s()) };
    static double dtAccumulator{};

    double deltaTime{ currentTime - lastTime };
    lastTime = currentTime;

    dtAccumulator += deltaTime;

    Vector2 windowSize{ Window::size() };
    m_projection = glm::ortho(0.0, windowSize.x, windowSize.y, 0.0);

    for (const auto &sprite : m_objects)
    {
        /// TODO: Batching.. this is very inefficient
        sprite->setProjectionMatrix(m_projection);
        sprite->setViewMatrix(m_view);
        sprite->draw(deltaTime);
    }
}

//------------------------------------------------------------------//

void RenderingManager::setViewMatrix(const glm::dmat4 &view)
{
    m_view = view;
}

//------------------------------------------------------------------//
