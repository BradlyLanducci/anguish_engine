#include <objects/sprite.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>

//------------------------------------------------------------------//

Sprite::Sprite()
    : RenderedObject(false, false)
{
}

//------------------------------------------------------------------//

void Sprite::draw(double deltaTime)
{
    auto translatedModel{ glm::translate(m_model, glm::dvec3(globalPosition().x, globalPosition().y, 1.0)) };
    auto rotatedModel{ glm::rotate(translatedModel, rotation(), glm::dvec3(0.0, 0.0, 1.0)) };
    auto scaledModel{ glm::scale(rotatedModel, glm::dvec3(size().x * scale().x, size().y * scale().y, 1.0)) };

    m_shaderProgram.p_vertexShader->setMat4("model", scaledModel);

    glUseProgram(m_shaderProgram.get());
    glBindVertexArray(m_vao.get());
    m_texture.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    checkGLError();
}

//------------------------------------------------------------------//