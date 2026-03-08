#pragma once

//------------------------------------------------------------------//

#include <texture/texture.h>

//------------------------------------------------------------------//

class Spritesheet
{
public:
    Spritesheet() = default;
    explicit Spritesheet(const std::string &spritesheetPath, int numFrames, int rows, int columns, int fps);

    void load(const std::string &spritesheetPath, int numFrames, int rows, int columns, int fps);

private:
    struct Frame
    {
        double duration{};
    };

    Texture m_texture;
    std::vector<Frame> m_frames;
};

//------------------------------------------------------------------//
