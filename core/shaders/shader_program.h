#pragma once

//------------------------------------------------------------------//

#include <ogl/gl_object.h>

#include <string>
#include <memory>

//------------------------------------------------------------------//

class Shader;

//------------------------------------------------------------------//

class ShaderProgram : public GlObject
{
public:
    /// @brief Creates a shader program. Internally holds a single vertex and fragment shader at one time
    explicit ShaderProgram(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);
    ~ShaderProgram() override;

    /// @brief Loads the provided path as a vertex shader.
    /// @param path
    void setVertexShader(const std::string &path);

    /// @brief Loads the provided path as a fragment shader.
    /// @param path
    void setFragmentShader(const std::string &path);

    std::unique_ptr<Shader> p_vertexShader{ nullptr };
    std::unique_ptr<Shader> p_fragmentShader{ nullptr };
};

//------------------------------------------------------------------//
