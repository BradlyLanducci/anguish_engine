#include <objects/rendered_object.h>
#include <ogl/vertices.h>
#include <ogl/gl_error.h>
#include <shaders/shader.h>
#include <renderer/rendering_manager.h>

//------------------------------------------------------------------//

RenderedObject::RenderedObject(bool doIdle, bool doPhysics)
    : m_shaderProgram("core/shaders/vert.glsl", "core/shaders/frag.glsl")
{
    RenderingManager::get().addObject(this);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo.get());
    checkGLError();
    glBufferData(GL_ARRAY_BUFFER, sizeof(QUAD_VERTICES), QUAD_VERTICES, GL_STATIC_DRAW);
    checkGLError();
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    checkGLError();
    glEnableVertexAttribArray(0);
    checkGLError();
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2 * sizeof(float)));
    checkGLError();
    glEnableVertexAttribArray(1);
    checkGLError();
    glBindVertexArray(m_vao.get());
    checkGLError();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo.get());
    checkGLError();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(QUAD_INDICES), QUAD_INDICES, GL_STATIC_DRAW);
    checkGLError();

    m_shaderProgram.p_fragmentShader->setInt("texture1", 0);
}

//------------------------------------------------------------------//

RenderedObject::~RenderedObject()
{
    RenderingManager::get().removeObject(this);
}

//------------------------------------------------------------------//

ShaderProgram &RenderedObject::shader()
{
    return m_shaderProgram;
}

//------------------------------------------------------------------//

void RenderedObject::setProjectionMatrix(const glm::dmat4 &projection) const
{
    m_shaderProgram.p_vertexShader->setMat4("projection", projection);
}

//------------------------------------------------------------------//

void RenderedObject::setViewMatrix(const glm::dmat4 &view) const
{
    m_shaderProgram.p_vertexShader->setMat4("view", view);
}

//------------------------------------------------------------------//

void RenderedObject::setTexture(const std::string &texturePath)
{
    m_texture.load(texturePath);
    setSize(Vector2(m_texture.size()));
}

//------------------------------------------------------------------//
