#pragma once

//------------------------------------------------------------------//

#include <objects/object.h>
#include <texture/texture.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <ogl/ebo.h>

#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class RenderedObject : public Object
{
public:
    RenderedObject();
    virtual ~RenderedObject();

    void setProjectionMatrix(const glm::dmat4 &projection) const;
    void setViewMatrix(const glm::dmat4 &view) const;
    virtual void draw(double deltaTime) = 0;

    ShaderProgram &shader();

    void setTexture(const std::string &texturePath);

protected:
    Texture m_texture;
    glm::dmat4 m_model{ 1.0 };
    ShaderProgram m_shaderProgram;
    VAO m_vao;
    VBO m_vbo;
    EBO m_ebo;
};

//------------------------------------------------------------------//
