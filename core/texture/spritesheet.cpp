#include <texture/spritesheet.h>

#include <math/vector2.h>

//------------------------------------------------------------------//

Spritesheet::Spritesheet(const std::string &spritesheetPath, uint32_t numFrames, uint32_t rows, uint32_t columns,
                         uint32_t fps, bool loops)
    : m_spritesheetPath(spritesheetPath)
    , m_numFrames(numFrames)
    , m_rows(rows)
    , m_columns(columns)
    , m_fps(fps)
    , m_frameDuration(1.0 / m_fps)
    , m_loops(loops)
{
    m_texture.load(spritesheetPath);
}

//------------------------------------------------------------------//

Vector2i Spritesheet::getCurrentFrame(double deltaTime)
{
    m_accumulator += deltaTime;

    while (m_accumulator >= m_frameDuration)
    {
        m_accumulator -= m_frameDuration;
        incrementCol();
    }

    return { m_currentColumn, m_currentRow };
}

//------------------------------------------------------------------//

bool Spritesheet::isComplete() const
{
    return !m_loops && !m_isPlaying;
}

//------------------------------------------------------------------//

void Spritesheet::reset()
{
    m_accumulator = 0.0;
    m_currentColumn = 0;
    m_currentRow = 0;
}

//------------------------------------------------------------------//

void Spritesheet::stop()
{
    m_isPlaying = false;
    reset();
}

//------------------------------------------------------------------//

void Spritesheet::start()
{
    if (m_isPlaying)
    {
        reset();
    }
    m_isPlaying = true;
}

//------------------------------------------------------------------//

std::string Spritesheet::spritesheetPath() const
{
    return m_spritesheetPath;
}

//------------------------------------------------------------------//

uint32_t Spritesheet::rows() const
{
    return m_rows;
}

//------------------------------------------------------------------//

uint32_t Spritesheet::columns() const
{
    return m_columns;
}

//------------------------------------------------------------------//

uint32_t Spritesheet::numFrames() const
{
    return m_numFrames;
}

//------------------------------------------------------------------//

Vector2 Spritesheet::frameSize() const
{
    return { 1.0 / static_cast<float>(m_columns), 1.0 / static_cast<double>(m_rows) };
}

//------------------------------------------------------------------//

Texture &Spritesheet::texture()
{
    return m_texture;
}

//------------------------------------------------------------------//

void Spritesheet::incrementCol()
{
    m_currentColumn++;
    if (m_currentColumn >= m_columns)
    {
        incrementRow();
        m_currentColumn = 0;
    }
}

//------------------------------------------------------------------//

void Spritesheet::incrementRow()
{
    m_currentRow++;
    if (m_currentRow >= m_rows)
    {
        reset();
        if (!m_loops)
        {
            m_isPlaying = false;
        }
    }
}

//------------------------------------------------------------------//
