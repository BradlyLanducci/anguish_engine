#include <ogl/vao.h>
#include <ogl/gl_error.h>

#include <glad/gl.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

VAO::VAO()
{
    glGenVertexArrays(1, &m_id);
    checkGLError();
    glBindVertexArray(m_id);
    checkGLError();
}

//------------------------------------------------------------------//

VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_id);
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
