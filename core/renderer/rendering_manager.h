#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class RenderedObject;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class RenderingManager
{
public:
    static RenderingManager &get();
    ~RenderingManager();

    void addObject(RenderedObject *p_object);
    void removeObject(RenderedObject *p_object);
    void update(double currentTime);

    void setViewMatrix(const glm::dmat4 &view);

    RenderingManager(const RenderingManager &) = delete;
    RenderingManager &operator=(const RenderingManager &) = delete;

private:
    RenderingManager() = default;

    static inline std::vector<RenderedObject *> m_objects;
    static inline glm::dmat4 m_projection{ 1.f };
    static inline glm::dmat4 m_view{ 1.f };
};

//------------------------------------------------------------------//
