#include <texture/spritesheet.h>

//------------------------------------------------------------------//

Spritesheet::Spritesheet(const std::string &spritesheetPath, int numFrames, int rows, int columns, int fps)
{
    load(spritesheetPath, numFrames, rows, columns, fps);
}

//------------------------------------------------------------------//

void Spritesheet::load(const std::string &spritesheetPath, int numFrames, int rows, int columns, int fps)
{
}

//------------------------------------------------------------------//
