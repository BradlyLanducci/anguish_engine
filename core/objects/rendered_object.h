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
    explicit RenderedObject(bool doIdle, bool doPhysics);
    ~RenderedObject();

    void setProjectionMatrix(const glm::dmat4 &projection) const;
    void setViewMatrix(const glm::dmat4 &view) const;
    void draw(double deltaTime);

    ShaderProgram &shader();

    void setTexture(const std::string &texturePath);

private:
    glm::dmat4 m_model{ 1.f };

    Texture m_texture;

    VAO m_vao;
    VBO m_vbo;
    EBO m_ebo;

    ShaderProgram m_shaderProgram;
};

//------------------------------------------------------------------//
