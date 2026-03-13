#pragma once

//------------------------------------------------------------------//

#include <cstdint>

//------------------------------------------------------------------//

// Base OpenGL Object
class GlObject
{
public:
    GlObject() = default;
    GlObject(uint32_t id)
        : m_id(id)
    {
    }

    virtual ~GlObject() = default;

    GlObject(const GlObject &other) = delete;
    GlObject &operator=(const GlObject &other) = delete;

    /// @brief The opengl handle for this object.
    /// @return
    [[nodiscard]] uint32_t get() const
    {
        return m_id;
    }

protected:
    uint32_t m_id{ 0 };
};

//------------------------------------------------------------------//