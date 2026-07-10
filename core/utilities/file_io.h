#pragma once

//------------------------------------------------------------------//

#include <utilities/logger.h>

#include <string>
#include <fstream>
#include <sstream>
#include <json/json.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

namespace FileIO
{
    /// @brief Reads a file and returns it as a string.
    /// @param path The file to read from.
    /// @return
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

    /// @brief Reads a file and returns it as a JSON object.
    /// @param path The file to read from.
    /// @return
    static Json::Value readJson(const std::string &path)
    {
        Json::CharReaderBuilder builder;

        Json::Value root;

        std::fstream file{ path, std::ios::in };

        if (file.is_open())
        {
            Json::String errors;

            if (!Json::parseFromStream(builder, file, &root, &errors))
            {
                Log(Error) << "Failed to read JSON for file: " << path << " with errors: " << errors;
            }
        }
        else
        {
            Log(Error) << "Failed to open file for reading: " << path;
        }

        return root;
    }

    /// @brief Writes a JSON object to a file.
    /// @param path The file to write to.
    /// @param json The JSON object to write to a file.
    /// @return
    static bool writeJson(const std::string &path, const Json::Value &json)
    {
        std::fstream file{ path, std::ios::out };

        if (!file.is_open())
        {
            Log(Error) << "Failed to open file for writing: " << path;
            return false;
        }

        file << json.toStyledString();

        return true;
    }
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
