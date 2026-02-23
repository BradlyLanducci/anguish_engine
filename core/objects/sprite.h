#pragma once

//------------------------------------------------------------------//

#include <objects/object.h>
#include <texture/texture.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <ogl/ebo.h>

//------------------------------------------------------------------//

class Sprite : public Object
{
public:
    Sprite();
    ~Sprite();

    void setProjectionMatrix(const glm::mat4 &projection) const;
    void setViewMatrix(const glm::mat4 &view) const;

    void setTexture(const std::string &texturePath);

    void draw();

protected:
    Texture m_texture;

    VAO m_vao;
    VBO m_vbo;
    EBO m_ebo;
    ShaderProgram m_shaderProgram;
    glm::mat4 m_model{ 1.f };
};

//------------------------------------------------------------------//
