#include <shaders/shader_program.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>

#include <glad/gl.h>

//------------------------------------------------------------------//

ShaderProgram::ShaderProgram(const std::string &vertexShaderPath, const std::string &fragmentShaderPath)
    : GlObject(glCreateProgram())
{
    setVertexShader(vertexShaderPath);
    setFragmentShader(fragmentShaderPath);
}

//------------------------------------------------------------------//

ShaderProgram::~ShaderProgram()
{
    if (p_vertexShader)
    {
        glDetachShader(m_id, p_vertexShader->get());
        checkGLError();
    }
    if (p_fragmentShader)
    {
        glDetachShader(m_id, p_fragmentShader->get());
        checkGLError();
    }
    glDeleteProgram(m_id);
    checkGLError();
}

//------------------------------------------------------------------//

void ShaderProgram::setVertexShader(const std::string &path)
{
    if (p_vertexShader)
    {
        glDetachShader(m_id, p_vertexShader->get());
        checkGLError();
        p_vertexShader->setShader(path, GL_VERTEX_SHADER);
    }
    else
    {
        p_vertexShader = std::make_unique<Shader>(m_id, path, GL_VERTEX_SHADER);
    }
    glAttachShader(m_id, p_vertexShader->get());
    checkGLError();
    glLinkProgram(m_id);
    checkGLError();
}

//------------------------------------------------------------------//

void ShaderProgram::setFragmentShader(const std::string &path)
{
    if (p_fragmentShader)
    {
        p_fragmentShader->setShader(path, GL_FRAGMENT_SHADER);
    }
    else
    {
        p_fragmentShader = std::make_unique<Shader>(m_id, path, GL_FRAGMENT_SHADER);
        glAttachShader(m_id, p_fragmentShader->get());
        checkGLError();
        glLinkProgram(m_id);
        checkGLError();
    }
}

//------------------------------------------------------------------//