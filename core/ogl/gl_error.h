#pragma once

//------------------------------------------------------------------//

#include <glad/glad.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

static void checkGLError()
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        Log(Error) << err << " ";
    }
}

//------------------------------------------------------------------//
