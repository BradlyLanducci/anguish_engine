#pragma once

//------------------------------------------------------------------//

#include <utilities/object_queue.h>

#include <vector>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class RenderedObject;

//------------------------------------------------------------------//

class RenderingManager
{
public:
    RenderingManager(const RenderingManager &) = delete;
    RenderingManager &operator=(const RenderingManager &) = delete;

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

    /// @brief Main render function for the rendering manager. This will be
    /// called once per game frame.
    void render();

private:
    RenderingManager() = default;

    static inline ObjectQueue<RenderedObject *> m_queue;

    static inline glm::dmat4 m_projection{ 1.0 };
    static inline glm::dmat4 m_view{ 1.0 };
};

//------------------------------------------------------------------//
