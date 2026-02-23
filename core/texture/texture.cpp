#include <texture/texture.h>
#include <ogl/gl_error.h>
#include <texture/texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>

//------------------------------------------------------------------//

Texture::Texture()
{
    glGenTextures(1, &m_id);
    checkGLError();
    glBindTexture(GL_TEXTURE_2D, m_id);
    checkGLError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    checkGLError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    checkGLError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    checkGLError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    checkGLError();
}

//------------------------------------------------------------------//

Vector2i Texture::size() const
{
    return m_size;
}

//------------------------------------------------------------------//

void Texture::setSize(Vector2i size)
{
    m_size = size;
}

//------------------------------------------------------------------//

void Texture::load(const std::string &path)
{
    int &x{ reinterpret_cast<int &>(m_originalSize.x) };
    int &y{ reinterpret_cast<int &>(m_originalSize.y) };

    mp_data = stbi_load(path.c_str(), &x, &y, &m_channels, 0);

    m_size = m_originalSize;

    if (mp_data)
    {
        glBindTexture(GL_TEXTURE_2D, m_id);
        checkGLError();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x, m_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, mp_data);
        checkGLError();
        glGenerateMipmap(GL_TEXTURE_2D);
        checkGLError();

        stbi_image_free(mp_data);
    }
    else
    {
        Log(Error) << "Failed to load texture with file path " << path;
    }
}

//------------------------------------------------------------------//

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, m_id);
    checkGLError();
}

//------------------------------------------------------------------//
