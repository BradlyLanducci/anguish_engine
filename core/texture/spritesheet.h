#pragma once

//------------------------------------------------------------------//

#include <texture/texture.h>
#include <utilities/signal.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

/*
    This utility class contains metadata about a spritesheet and can receive time
    to get the next frame based on it's own internal time accumualator.
*/
class Spritesheet
{
public:
    Spritesheet() = default;
    explicit Spritesheet(const std::string &spritesheetPath, int numFrames, int rows, int columns, int fps, bool loops);

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
    int rows() const;
    int columns() const;
    int numFrames() const;
    Vector2 frameSize() const;

    Texture &texture();

    Signal<> animationFinished;

private:
    void reset();

    void incrementCol();
    void incrementRow();

    std::string m_spritesheetPath;
    int m_numFrames{};
    int m_rows{};
    int m_columns{};
    int m_fps{};

    double m_frameDuration{};
    int m_currentRow{};
    int m_currentColumn{};
    double m_accumulator{};

    bool m_loops{ false };
    bool m_isPlaying{ false };

    Texture m_texture;
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
