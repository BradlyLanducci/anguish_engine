#pragma once

//------------------------------------------------------------------//

#include <utilities/vector2i.h>
#include <shaders/shader_program.h>

#include <cstdint>
#include <array>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class Texture : public GlObject
{
public:
    Texture();
    ~Texture() override = default;

    [[nodiscard]] Vector2i size() const;
    void setSize(Vector2i size);

    void load(const std::string &path);

    void bind();

protected:
    uint8_t *mp_data{ nullptr };
    Vector2i m_originalSize;
    Vector2i m_size;
    int m_channels{ 0 };
};

//------------------------------------------------------------------//
