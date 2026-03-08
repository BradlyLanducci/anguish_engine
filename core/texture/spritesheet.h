#pragma once

//------------------------------------------------------------------//

#include <texture/texture.h>

#include <utilities/logger.h>

//------------------------------------------------------------------//

/*
    This utility class contains metadata about a spritesheet and can receive time
    to get the next frame based on it's own internal time accumualator.
*/
class Spritesheet
{
public:
    Spritesheet() = default;
    explicit Spritesheet(const std::string &spritesheetPath, uint32_t numFrames, uint32_t rows, uint32_t columns,
                         uint32_t fps, bool loops);

    Vector2i getCurrentFrame(double deltaTime);

    bool isComplete() const;

    void stop();
    void start();

    std::string spritesheetPath() const;
    uint32_t rows() const;
    uint32_t columns() const;
    uint32_t numFrames() const;
    Vector2 frameSize() const;

    Texture &texture();

private:
    void reset();

    void incrementCol();
    void incrementRow();

    std::string m_spritesheetPath;
    uint32_t m_numFrames{};
    uint32_t m_rows{};
    uint32_t m_columns{};
    uint32_t m_fps{};

    double m_frameDuration{};
    uint32_t m_currentRow{};
    uint32_t m_currentColumn{};
    double m_accumulator{};

    bool m_loops{ false };
    bool m_isPlaying{ false };

    Texture m_texture;
};

//------------------------------------------------------------------//
