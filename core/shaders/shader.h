#pragma once

//------------------------------------------------------------------//

#include <ogl/gl_object.h>
#include <utilities/vector2.h>
#include <utilities/vector2i.h>

#include <string>
#include <glad/glad.h>

#include <glm/glm.hpp>

//------------------------------------------------------------------//

class Shader : public GlObject
{
public:
    /// @brief Creates a shader from a provided file path
    /// @param shaderProgram Shader program id
    /// @param path Path to shader
    /// @param shaderType Type of shader
    Shader(uint32_t shaderProgram, const std::string &path, GLenum shaderType);
    ~Shader() override;

    /// @brief Sets and compiles new shader
    /// @param path
    /// @param shaderType Type of shader
    void setShader(const std::string &path, GLenum shaderType);

    /// @brief Various functions to set shader uniforms
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, glm::mat4 value) const;
    void setVec2i(const std::string &name, Vector2i value) const;
    void setVec2(const std::string &name, Vector2 value) const;

private:
    uint32_t m_shaderProgram{ 0 };
};

//------------------------------------------------------------------//
