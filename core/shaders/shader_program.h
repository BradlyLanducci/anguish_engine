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
    ShaderProgram();
    ~ShaderProgram() override;

    void setVertexShader(const std::string &path);
    void setFragmentShader(const std::string &path);

    std::unique_ptr<Shader> p_vertexShader{ nullptr };
    std::unique_ptr<Shader> p_fragmentShader{ nullptr };
};

//------------------------------------------------------------------//
