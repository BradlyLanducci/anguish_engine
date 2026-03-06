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

    m_shaderProgram.p_fragmentShader->setInt("texture1", 0);
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
    m_shaderProgram.p_vertexShader->setMat4("projection", projection);
}

//------------------------------------------------------------------//

void Sprite::setViewMatrix(const glm::mat4 &view) const
{
    m_shaderProgram.p_vertexShader->setMat4("view", view);
}

//------------------------------------------------------------------//

void Sprite::draw()
{
    auto translatedModel{ glm::translate(m_model, glm::vec3(globalPosition().x, globalPosition().y, 1.f)) };
    auto rotatedModel{ glm::rotate(translatedModel, rotation(), glm::vec3(0.f, 0.f, 1.f)) };
    auto scaledModel{ glm::scale(rotatedModel, glm::vec3(size().x * scale().x, size().y * scale().y, 1.f)) };

    m_shaderProgram.p_vertexShader->setMat4("model", scaledModel);

    glUseProgram(m_shaderProgram.get());
    glBindVertexArray(m_vao.get());
    m_texture.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    checkGLError();
}

//------------------------------------------------------------------//
