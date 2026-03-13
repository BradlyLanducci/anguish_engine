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

    /// @brief Gets the current frame of this animation based off the internal accumulator.
    /// @param deltaTime Adds this amount of time to the internal accumulator.
    /// @return
    Vector2i getCurrentFrame(double deltaTime);

    /// @brief Whether this animation has finished or never been started.
    /// @return
    bool isComplete() const;

    /// @brief Stops this animation.
    void stop();

    /// @brief Starts this animation. This will reset the animation if it's already playing.
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
