#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <utilities/logger.h>

//------------------------------------------------------------------//

namespace FileIO
{
    static std::string toString(const std::string &path)
    {
        std::stringstream buffer;
        std::string data{};
        std::ifstream file(path);
        if (file.is_open())
        {
            buffer << file.rdbuf();
        }
        else
        {
            Log(Warning) << "Failed to load " << path;
        }
        return buffer.str();
    }
}

//------------------------------------------------------------------//
