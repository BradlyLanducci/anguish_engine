#include <objects/sprite.h>
#include <renderer/rendering_manager.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>
#include <ogl/vertices.h>

//------------------------------------------------------------------//

Sprite::Sprite()
{
    RenderingManager::get().addSprite(this);

    m_shaderProgram.setVertexShader("core/shaders/vert.glsl");
    m_shaderProgram.setFragmentShader("core/shaders/frag.glsl");

    glUseProgram(m_shaderProgram.get());
    checkGLError();
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

    m_shaderProgram.mp_fragmentShader->setInt("texture1", 0);
}

//------------------------------------------------------------------//

Sprite::~Sprite()
{
    RenderingManager::get().removeSprite(this);
}

//------------------------------------------------------------------//

void Sprite::setTexture(const std::string &texturePath)
{
    m_texture.load(texturePath);
    setSize(Vector2(m_texture.size()));
}

//------------------------------------------------------------------//

void Sprite::setProjectionMatrix(const glm::mat4 &projection) const
{
    m_shaderProgram.mp_vertexShader->setMat4("projection", projection);
}

//------------------------------------------------------------------//

void Sprite::setViewMatrix(const glm::mat4 &view) const
{
    m_shaderProgram.mp_vertexShader->setMat4("view", view);
}

//------------------------------------------------------------------//

void Sprite::draw()
{
    m_shaderProgram.mp_vertexShader->setMat4("model", m_model);
    m_shaderProgram.mp_vertexShader->setVec2("globalPos", globalPosition());
    m_shaderProgram.mp_vertexShader->setVec2("spriteSize", size() * scale());
    glUseProgram(m_shaderProgram.get());
    glBindVertexArray(m_vao.get());
    m_texture.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    checkGLError();
}

//------------------------------------------------------------------//
