#pragma once

//------------------------------------------------------------------//

#include <ogl/gl_object.h>

#include <cstdint>

//------------------------------------------------------------------//

// Element Buffer Object
class EBO final : public GlObject
{
public:
    EBO();
    ~EBO() override;
};

//------------------------------------------------------------------//
