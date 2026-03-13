#pragma once

//------------------------------------------------------------------//

#include <utilities/object_queue.h>

#include <vector>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class Game;
class RenderedObject;

//------------------------------------------------------------------//

class RenderingManager
{
public:
    static RenderingManager &get();

    /// @brief Releases all objects owned by this manager.
    void destroy();

    /// @brief Adds a object at the beginning of the rendering frame.
    /// @param p_object
    void addObject(RenderedObject *p_object);

    /// @brief Removes a object at the beginning of the rendering frame.
    /// @param p_object
    void removeObject(RenderedObject *p_object);

    /// @brief Sets the current view matrix to be used by all rendered objects.
    /// @param view
    void setViewMatrix(const glm::dmat4 &view);

    RenderingManager(const RenderingManager &) = delete;
    RenderingManager &operator=(const RenderingManager &) = delete;

private:
    RenderingManager() = default;

    friend Game;

    /// @brief Main update function for the rendering manager. This will be
    /// called once per game frame.
    void update(double currentTime);

    static inline ObjectQueue<RenderedObject *> m_queue;

    static inline glm::dmat4 m_projection{ 1.0 };
    static inline glm::dmat4 m_view{ 1.0 };
};

//------------------------------------------------------------------//
